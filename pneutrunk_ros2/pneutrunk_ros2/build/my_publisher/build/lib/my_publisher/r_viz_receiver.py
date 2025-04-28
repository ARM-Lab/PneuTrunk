import math
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import JointState


class RvizPublisher(Node):
    def __init__(self):
        super().__init__('rviz_publisher')

        # Паблишер для joint_states
        self.joint_pub = self.create_publisher(JointState, '/joint_states', 10)

        self.marker_pub = self.create_publisher(Marker, '/visualization_marker', 10)


        # Подписки на углы
        self.subscription_x = self.create_subscription(Float32MultiArray, 'UhlyX_topic', self.callback_x, 10)
        self.subscription_y = self.create_subscription(Float32MultiArray, 'UhlyY_topic', self.callback_y, 10)

        # Списки имен суставов (УБЕДИСЬ, что такие есть в URDF!)
        self.joint_names_x = ['Revolute2', 'Revolute6', 'Revolute10',
                              'Revolute20', 'Revolute24', 'Revolute28', 'Revolute32']
        self.joint_names_y = ['Revolute3', 'Revolute7', 'Revolute11',
                              'Revolute21', 'Revolute25', 'Revolute29', 'Revolute33']

        # Храним последние данные
        self.uhly_x = []
        self.uhly_y = []

        self.bias_x = [-2.03, -1.25, -0.99, -1.77, -2.03, 1.08, 1.08]
        self.bias_y = [-0.47, -4.11, -2.55, -3.0, 1.08, -4.11, -3.85]

        # Флаг и сообщение
        self.joint_msg_ready = False
        self.last_joint_msg = JointState()

        # Таймер на публикацию каждые 100 мс
        self.timer = self.create_timer(0.1, self.timer_callback)

    def callback_x(self, msg):
        self.uhly_x = msg.data
        self.try_build_joint_msg()

    def callback_y(self, msg):
        self.uhly_y = msg.data
        self.try_build_joint_msg()

    def try_build_joint_msg(self):
        # Ждём, пока обе оси будут получены
        if len(self.uhly_x) == len(self.uhly_y) and len(self.uhly_x) > 0:
            joint_msg = JointState()
            joint_msg.header.stamp = self.get_clock().now().to_msg()

            count = min(len(self.uhly_x), len(self.uhly_y), len(self.joint_names_x), len(self.joint_names_y))
            joint_msg.name = self.joint_names_x[:count] + self.joint_names_y[:count]

            position_x = [math.radians(self.uhly_x[a] - self.bias_x[a]) for a in range(count)]
            position_y = [math.radians(self.uhly_y[b] - self.bias_y[b]) for b in range(count)]

            self.last_joint_msg = joint_msg
            self.joint_msg_ready = True

    def timer_callback(self):
        if self.joint_msg_ready:
            self.last_joint_msg.header.stamp = self.get_clock().now().to_msg()
            self.joint_pub.publish(self.last_joint_msg)
            #self.get_logger().info(f"[RViZ] Published joint_states: {self.last_joint_msg.position}")

def main(args=None):
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
