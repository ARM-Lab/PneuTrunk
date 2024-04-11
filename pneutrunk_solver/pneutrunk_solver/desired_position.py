import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from sensor_msgs.msg import Joy
from std_msgs.msg import Header
from math import modf
import time
import numpy as np
from pneutrunk_msgs.msg import PneutrunkJointState 

class DesiredPosition(Node):
    # ros2 run joy joy_node
    def __init__(self):
        super().__init__("desired_position")
        self.publisher_ = self.create_publisher(Pose, '/pneutrunk/desired_position/cmd',10)
        #self.subscriber_ = self.create_subscription(Joy, "/joy",self.joystick_detection, 10)
        self.subscriber2_ = self.create_subscription(PneutrunkJointState, "/pneutrunk/joints/state", self.is_in_workspace, 10)
        self.timer_ = self.create_timer(0.01, self.position)
        self.get_logger().info("Desired position...")
        self.z = 978
        self.x = 0
        self.y = 0
        self.workspace = False
        self.end_effector = np.array([self.x, self.y, self.z])
    
    def joystick_detection(self, msg_joystick):
        current_time = modf(time.time())
        uhly = np.zeros(6)
        self.msg_common_stamped_header = Header()
        axes = msg_joystick.axes
        buttons = msg_joystick.buttons

        if self.workspace == True:
            # zapis hodnot ak by po vykonani posuvu end-effectora sa dostal mimo workspacu
            self.end_effector = [self.x, self.y, self.z]
            if axes[0] < -0.5 and buttons[0] == 0:
                self.x = self.x - 1
            if axes[0] > 0.5 and buttons[0] == 0:
                self.x = self.x + 1
            if axes[1] < -0.5 and buttons[0] == 0:
                self.y = self.y - 1
            if axes[1] > 0.5 and buttons[0] == 0:
                self.y = self.y + 1
            if axes[1] > 0.5 and buttons[0] == 1:
                self.z = self.z + 1
            if axes[1] < -0.5 and buttons[0] == 1:
                self.z = self.z - 1
        else:
            self.x = self.end_effector[0]
            self.y = self.end_effector[1]
            self.z = self.end_effector[2]
    
    def is_in_workspace(self, msg):
        rev_joint = msg.segment_state
        lin_joint = msg.translation
        result = True
        for i in range(12):
            if rev_joint[i] >= 20 or rev_joint[i] <= -20:
                result = False
        self.workspace = result        

    def position(self):
        msg_object = Pose()
        #num = random.random()
        msg_object.position.x = 0.0#float(self.x)
        msg_object.position.y = -300.0#float(self.y)
        msg_object.position.z = 900.0#float(self.z)
        self.publisher_.publish(msg_object)

def main(args=None):
    rclpy.init(args=args)
    node = DesiredPosition()  
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()