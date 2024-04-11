import rclpy
import socket
from rclpy.node import Node
import numpy as np
from pneutrunk_msgs.msg import PneutrunkJointState

class PLCmessage(Node):

    def __init__(self):
        super().__init__("plc_message")
        self.publisher_ = self.create_publisher(PneutrunkJointState, '/pneutrunk/joints/state',10)
        self.timer_ = self.create_timer(0.001, self.plc_receiver)
        self.get_logger().info("PLC listener started...")

    def plc_receiver(self):
        localIP = "192.168.1.43" #41
        localPort = 12050
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_address = (localIP, localPort)
        sock.bind(server_address)
        data, addr = sock.recvfrom(1024)  
        q_udp = data.decode('utf-8')
        q_string = str(q_udp)
        q_real = q_string.split(',')
        joint_state = PneutrunkJointState()
        q = np.zeros(12)
        for i in range(12):
            q[i] = float(q_real[i])
        joint_state.segment_state = q
        joint_state.translation = 0.0#float(q_real[12])
        self.publisher_.publish(joint_state)
        self.get_logger().info("PLC:"+str(joint_state))

def main(args=None):
    rclpy.init(args=args)
    node = PLCmessage()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()