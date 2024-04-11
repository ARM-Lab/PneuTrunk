#!/usr/bin/env python3
import rclpy
import math
import numpy as np
from rclpy.node import Node
from scipy import optimize
from scipy.optimize import Bounds
from std_msgs.msg import String
from geometry_msgs.msg import Pose
from pneutrunk_msgs.msg import PneutrunkJointState
import socket
import pickle

class InverseKinematicsSolver(Node):

    # =========================================================
    # ================= Variables declaration =================
    # =========================================================
    # UDP parameters
    UDP_IP = "192.168.1.38"             # IP address of PLC
    UDP_PORT = 12050    
    # Robot parameters:
    effector = np.zeros(3)              # effector = [x, y, z]
    q_real = np.zeros(13)
    packet_start = ""
    gesture = ""
    ball_color = ""
    # =========================================================

    # =========================================================
    # ================== Default constructor ==================
    # =========================================================
    def __init__(self):
        super().__init__("ik_solver")
        self.publisher_ = self.create_publisher(String, "/pneutrunk/ik_solver", 100)
        self.subscriber1_ = self.create_subscription(PneutrunkJointState, "/pneutrunk/joints/state", self.q_real_detection, 10)
        self.subscriber2_ = self.create_subscription(String, "/pneutrunk/gesture/cmd", self.gesture_detection, 10)
        self.subscriber3_ = self.create_subscription(Pose, "/pneutrunk/desired_position/cmd", self.desired_position, 10)
        self.subscriber4_ = self.create_subscription(String, "/pneutrunk/object_color", self.ball_color_detection, 10)
        #self.subscriber3_ = self.create_subscription(Pose, "/pneutrunk/object_detection/cmd", self.object_detection, 10)
        self.get_logger().info("IK Solver has been started...1")
    # =========================================================

    # =========================================================
    # ================= Ball color detection ==================
    # =========================================================
    def ball_color_detection(self, msg):
        self.ball_color = msg.data

    # =========================================================
    # ================ Desired position change ================
    # =========================================================
    def desired_position(self, msg):
        self.effector[0] = round(msg.position.x, 2)
        self.effector[1] = round(msg.position.y, 2)
        self.effector[2] = round(msg.position.z, 2)
  
    # =========================================================
    # =============== Categorization of gestures ==============
    # =========================================================
    def gesture_detection(self, msg):
        self.gesture = msg.data
        if(self.gesture == "Right:Open"):
            self.packet_start = "s:come,q:"
        elif(self.gesture == "Right:Close"):
            self.packet_start = "s:continue,q:"
        elif(self.gesture == "Left:Open"):
            self.packet_start = "s:release,q:"
        elif(self.gesture == "Left:Close"):
            self.packet_start = "s:grasp,q:"
        self.solver_sqp(self.q_real)
        
    # =========================================================
    # ========= Generalized variables vector from PLC =========
    # =========================================================
    def q_real_detection(self, msg):
        q_real_state_temp = msg.segment_state
        q_real_tran_temp = msg.translation
        for i in range(12):
            self.q_real[i] = q_real_state_temp[i]
        self.q_real[12] = q_real_tran_temp
        #self.q_real.append = 0.0#msg.translation
        #self.get_logger().info("q_real_detection")

    # =========================================================
    # ============== Object detection from d435i ==============
    # =========================================================
    def object_detection(self, msg):
        self.effector[0] = round(msg.position.x, 2)
        self.effector[1] = round(msg.position.y, 2)
        self.effector[2] = round(msg.position.z, 2)

    """    
    def publisher_udp(self):
        UDP_IP = "192.168.1.38"
        UDP_PORT = 12050
        MESSAGE = b"q:12.25,20.25,16.78,-14.75,21.47,5.27,-7.87,13.65,9.25,-14.25,11.11,-10.45,20.25c:0,0,1,0,0,0,0,0,0,0,1,0,0,0"
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        msg = String()
        msg.data = "a"
        sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
    """    
    # =========================================================
    # =============== Inverse kinematics solver ===============
    # =========================================================
    """ PACKET from PC to PLC
    s:move      -   robot motion to desired XYZ position
    s:grasp     -   graps an object
    s:home      -   robot motion to home position
    s:release   -   release an object
    """
    def solver_sqp(self, q0):
        #self.get_logger().info("solver_sqp")
        q_required = np.zeros(13)
        qRotMin = -15.0         # min. revolute joints limit
        qRotMax = 15.0          # max. revolute joints limit
        qLinMin = 0.0           # min. translation joints limit
        qLinMax = 40.0          # max. translation joints limit
        lb = [qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qRotMin, qLinMin]
        ub = [qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qRotMax, qLinMax]
        bounds = ((qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qRotMin, qRotMax), (qLinMin, qLinMax))
        # SQP Optimization 
        result = optimize.minimize(self.obj_function, q0, method='SLSQP', bounds=bounds)
        for i in range(13):
            q_required[i] = round(result.x[i], 2)
        message = self.ball_color + "," + self.packet_start
        for i in range(13):
            message = message + str(q_required[i]) + ","
        message = message + "c:0,0,0,0,0,0,0,0,0,0,0,0"
        message = str.encode(message)
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.sendto(message, (self.UDP_IP, self.UDP_PORT))
        self.get_logger().info("message:"+str(message))

    # =========================================================
    # ================== Objective function ===================
    # =========================================================
    def obj_function(self, q):
        x_real = self.forward_kinematics(q)
        x_des = np.array([1.0, 0.0, 0.0, self.effector[0], 0.0, 1.0, 0.0, self.effector[1], 0.0, 0.0, 1.0, -self.effector[2], 0.0, 0.0, 0.0, 1.0])
        error = np.linalg.norm(x_des - x_real)
        #print("error:"+str(error))
        return error
    
    # =========================================================
    # ================== Forward Kinematics ===================
    # =========================================================
    def forward_kinematics(self, q):
        r1 = -173/2
        r2 = -115/2

        A01 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r1], [0, 0, 0, 1]]
        A12 = [[math.cos(math.radians(q[0])), 0, math.sin(math.radians(q[0])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[0])), 0, math.cos(math.radians(q[0])), 0], [0, 0, 0, 1]]
        A23 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[1])), -math.sin(math.radians(q[1])), 0], [0, math.sin(math.radians(q[1])), math.cos(math.radians(q[1])), 0], [0, 0, 0, 1]]
        A34 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r1], [0, 0, 0, 1]]
        T04 = np.dot(np.dot(np.dot(A01, A12), A23), A34)

        A45 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r1], [0, 0, 0, 1]]
        T05 = np.dot(T04, A45)
        A56 = [[math.cos(math.radians(q[2])), 0, math.sin(math.radians(q[2])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[2])), 0, math.cos(math.radians(q[2])), 0], [0, 0, 0, 1]]
        A67 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[3])), -math.sin(math.radians(q[3])), 0], [0, math.sin(math.radians(q[3])), math.cos(math.radians(q[3])), 0], [0, 0, 0, 1]]
        A78 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r1], [0, 0, 0, 1]]
        T08 = np.dot(np.dot(np.dot(np.dot(T04, A45), A56), A67), A78)

        A89 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T09 = np.dot(T08, A89)
        A910 = [[math.cos(math.radians(q[4])), 0, math.sin(math.radians(q[4])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[4])), 0, math.cos(math.radians(q[4])), 0], [0, 0, 0, 1]]
        A1011 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[5])), -math.sin(math.radians(q[5])), 0], [0, math.sin(math.radians(q[5])), math.cos(math.radians(q[5])), 0], [0, 0, 0, 1]]
        A1112 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T012 = np.dot(np.dot(np.dot(np.dot(T08, A89), A910), A1011), A1112)

        A1213 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T013 = np.dot(T012, A1213)
        A1314 = [[math.cos(math.radians(q[6])), 0, math.sin(math.radians(q[6])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[6])), 0, math.cos(math.radians(q[6])), 0], [0, 0, 0, 1]]
        A1415 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[7])), -math.sin(math.radians(q[7])), 0], [0, math.sin(math.radians(q[7])), math.cos(math.radians(q[7])), 0], [0, 0, 0, 1]]
        A1516 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T016 = np.dot(np.dot(np.dot(np.dot(T012, A1213), A1314), A1415), A1516)

        A1617 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T017 = np.dot(T016, A1617)
        A1718 = [[math.cos(math.radians(q[8])), 0, math.sin(math.radians(q[8])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[8])), 0, math.cos(math.radians(q[8])), 0], [0, 0, 0, 1]]
        A1819 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[9])), -math.sin(math.radians(q[9])), 0], [0, math.sin(math.radians(q[9])), math.cos(math.radians(q[9])), 0], [0, 0, 0, 1]]
        A1920 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T020 = np.dot(np.dot(np.dot(np.dot(T016, A1617), A1718), A1819), A1920)

        A2021 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T021 = np.dot(T020, A2021)
        A2122 = [[math.cos(math.radians(q[10])), 0, math.sin(math.radians(q[10])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[10])), 0, math.cos(math.radians(q[10])), 0], [0, 0, 0, 1]]
        A2223 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[11])), -math.sin(math.radians(q[11])), 0], [0, math.sin(math.radians(q[11])), math.cos(math.radians(q[11])), 0], [0, 0, 0, 1]]
        A2324 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T024 = np.dot(np.dot(np.dot(np.dot(T020, A2021), A2122), A2223), A2324)

        A2425 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 3*r2 + q[12]], [0, 0, 0, 1]]
        T025 = np.dot(T024, A2425)
        result = np.reshape(T025, -1)
        return result
    # =========================================================
    
def main(args=None):
    rclpy.init(args=args)
    node = InverseKinematicsSolver()     
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
