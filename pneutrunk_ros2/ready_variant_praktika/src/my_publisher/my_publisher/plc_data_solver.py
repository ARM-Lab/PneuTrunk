"""
plc_data_solver.py

ROS 2 node for receiving data from a PLC via UDP and publishing it to ROS 2 topics.

Publishes:
  - /UhlyX_topic (Float32MultiArray): X angle data
  - /UhlyY_topic (Float32MultiArray): Y angle data
  - /Narazy_topic (Bool): contact/collision state

Author: [Hlieb Hrinchenko]
Date: [31/03/2025]
"""


import socket  # For network communication (creating servers and clients).
import rclpy  # ROS 2 library for managing nodes and exchanging messages.
from rclpy.node import Node  # Class to create ROS 2 nodes for message handling.
from std_msgs.msg import Float32MultiArray, Bool  # Message types for sending arrays of floats and booleans.
import threading  # For running tasks in parallel (multithreading).


class PLCDataProcessor(Node):
    
    def __init__(self):
        super().__init__('plc_data_processor')

        # UDP settings
        
        self.pc_ip = "192.168.1.88"  # IP of your PC
        self.pc_port = 12050  # Port to receive data
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((self.pc_ip, self.pc_port))
        self.sock.settimeout(5.0)  # Timeout to prevent freezing

        self.get_logger().info(f"Listening for UDP data on {self.pc_ip}:{self.pc_port}")
        self.timeout_logged = False
        # The publishers of ROS 2
        self.publisher_x = self.create_publisher(Float32MultiArray, 'UhlyX_topic', 10)
        self.publisher_y = self.create_publisher(Float32MultiArray, 'UhlyY_topic', 10)
        self.publisher_narazy = self.create_publisher(Bool, 'Narazy_topic', 10)

        # Infinite loop of UDP listening
        self.run_udp_listener()
        
        
    def run_udp_listener(self):
        """UDP Data Receive Cycle"""
        while rclpy.ok():
            try:
                
                data, addr = self.sock.recvfrom(1024)  # Receive the packet
                decoded_data = data.decode().strip()  # Decode the string
                self.get_logger().info(f"Received from {addr}: {decoded_data}")
                self.process_data(decoded_data)
                
                self.timeout_logged = False

            except socket.timeout:
                if not self.timeout_logged:
                    self.get_logger().warn("UDP Receive Error: timed out")  # Logging only ONE time
                    self.timeout_logged = True  # Set the flag to no longer logging
            except Exception as e:
                self.get_logger().error(f"UDP Receive Error: {e}")
            
    def process_data(self, decoded_data):
        """Parses a string and sends the data to ROS 2"""
        try:
            decoded_data = decoded_data.replace(",end", "")

            uhlyX_str = decoded_data.split("UhlyX:")[1].split("UhlyY:")[0].rstrip(',')
            uhlyY_str = decoded_data.split("UhlyY:")[1].split("Narazy:")[0].rstrip(',')
            narazy_str = decoded_data.split("Narazy:")[1]

            UhlyX = [float(x) for x in uhlyX_str.split(",")]
            UhlyY = [float(y) for y in uhlyY_str.split(",")]
            Narazy = [n == 'True' for n in narazy_str.split(",")]

            self.publish_data(UhlyX, UhlyY, Narazy)

        except Exception as e:
            self.get_logger().error(f"Parsing Error: {e}")

    def publish_data(self, UhlyX, UhlyY, Narazy):
        """Publishes data to ROS 2"""
        msg_x = Float32MultiArray(data=UhlyX)
        msg_y = Float32MultiArray(data=UhlyY)
        self.publisher_x.publish(msg_x)
        self.publisher_y.publish(msg_y)

        for state in Narazy:
            msg_narazy = Bool(data=state)
            self.publisher_narazy.publish(msg_narazy)

        self.get_logger().info(f"Published UhlyX:")
        for x in UhlyX:
            self.get_logger().info(f"  {x}")
        self.get_logger().info(f"Published UhlyY:")
        for y in UhlyY:
            self.get_logger().info(f"  {y}")
        self.get_logger().info(f"Published Narazy:")
        for z in Narazy:
            self.get_logger().info(f"  {z}")

def main(args=None):
    """Main function to run the node."""
    rclpy.init(args=args)
    node = PLCDataProcessor()
    try:
        rclpy.spin(node)  
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
