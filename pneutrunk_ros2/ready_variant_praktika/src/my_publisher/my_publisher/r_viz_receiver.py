"""
r_viz_receiver.py

ROS 2 node for converting received joint angle data into JointState messages
for visualization in RViz.

Subscriptions:
  - /UhlyX_topic (Float32MultiArray): angles for X-axis joints
  - /UhlyY_topic (Float32MultiArray): angles for Y-axis joints

Publishes:
  - /joint_states (sensor_msgs/JointState): used by RViz to visualize robot joint states

Make sure that the joint names listed in `joint_names_x` and `joint_names_y` match
those defined in your robot's URDF model.

Author: [Hlieb Hrinchenko]
Date: [31/03/2025]
"""




import math  # Standard Python library for math operations (used for converting degrees to radians)

import rclpy  # Core ROS 2 Python client library (used to initialize and run ROS nodes)

from rclpy.node import Node  # Base class for creating custom ROS 2 nodes

from std_msgs.msg import Float32MultiArray  # ROS 2 message type for arrays of float numbers (used for UhlyX and UhlyY data)

from sensor_msgs.msg import JointState  # Standard ROS 2 message type for publishing joint names and positions


class RvizPublisher(Node):
    def __init__(self):
        super().__init__('rviz_publisher')

        # Publishers for joint_states
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)



        # Subscriptions to the angles
        self.subscription_x = self.create_subscription(Float32MultiArray, 'UhlyX_topic', self.callback_x, 10)
        self.subscription_y = self.create_subscription(Float32MultiArray, 'UhlyY_topic', self.callback_y, 10)

        # Lists of joint names (make sure these are in URDF!)
        self.joint_names_x = ['Revolute2', 'Revolute6', 'Revolute10',
                              'Revolute20', 'Revolute24', 'Revolute28', 'Revolute32']
        self.joint_names_y = ['Revolute3', 'Revolute7', 'Revolute11',
                              'Revolute21', 'Revolute25', 'Revolute29', 'Revolute33']

        # Storing the latest data
        self.uhly_x = []
        self.uhly_y = []

        #Angle accuracy data for the robot positioning in the simulation 
        self.bias_x = [-2.03, -1.25, -0.99, -1.77, -2.03, 1.08, 1.08]
        self.bias_y = [-0.47, -4.11, -2.55, -3.0, 1.08, -4.11, -3.85]

        # Flag and message
        self.joint_msg_ready = False
        self.last_joint_msg = JointState()

        # Timer to publish every 100ms
        self.timer = self.create_timer(0.1, self.timer_callback)

    def callback_x(self, msg):
        """Callback for UhlyX_topic - saves the obtained angles on the X axis."""
        self.uhly_x = msg.data
        self.try_build_joint_msg()

    def callback_y(self, msg):
        """Callback for UhlyY_topic - saves the obtained angles on the Y axis."""
        self.uhly_y = msg.data
        self.try_build_joint_msg()

    def try_build_joint_msg(self):
         # Proceed only if both angle arrays are received and have the same length
        if len(self.uhly_x) == len(self.uhly_y) and len(self.uhly_x) > 0:
            joint_msg = JointState()
            joint_msg.header.stamp = self.get_clock().now().to_msg()

            # Calculate the number of joints we can safely process
            count = min(len(self.uhly_x), len(self.uhly_y), len(self.joint_names_x), len(self.joint_names_y))

            # Add joint names (first X, then Y)
            joint_msg.name = self.joint_names_x[:count] + self.joint_names_y[:count]

            # Apply bias correction and convert degrees to radians
            position_x = [math.radians(self.uhly_x[a] - self.bias_x[a]) for a in range(count)]
            position_y = [math.radians(self.uhly_y[b] - self.bias_y[b]) for b in range(count)]

            # Combine all joint angles into one list
            joint_msg.position = position_x + position_y    

            # Save the message and mark it ready for publishing
            self.last_joint_msg = joint_msg
            self.joint_msg_ready = True

    def timer_callback(self):
    # Check if a joint message is ready to publish
        if self.joint_msg_ready:
            # Update timestamp before publishing
            self.last_joint_msg.header.stamp = self.get_clock().now().to_msg()

            # Publish the last joint state message to /joint_states
            self.joint_pub.publish(self.last_joint_msg)

            # Optional: log the published positions
            # self.get_logger().info(f"[RViZ] Published joint_states: {self.last_joint_msg.position}")


def main(args=None):
    """Main function to run the node."""
    rclpy.init(args=args)
    node = RvizPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
