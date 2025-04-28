import socket
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, Bool
import threading 

class PLCDataProcessor(Node):
    
    def __init__(self):
        super().__init__('plc_data_processor')

        # Настройки UDP
        
        self.pc_ip = "192.168.1.88"  # IP твоего ПК
        self.pc_port = 12050  # Порт для приема данных
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((self.pc_ip, self.pc_port))
        self.sock.settimeout(5.0)  # Таймаут для предотвращения зависания

        self.get_logger().info(f"Listening for UDP data on {self.pc_ip}:{self.pc_port}")
        self.timeout_logged = False
        # Издатели ROS 2
        self.publisher_x = self.create_publisher(Float32MultiArray, 'UhlyX_topic', 10)
        self.publisher_y = self.create_publisher(Float32MultiArray, 'UhlyY_topic', 10)
        self.publisher_narazy = self.create_publisher(Bool, 'Narazy_topic', 10)

        # Бесконечный цикл прослушивания UDP
        self.run_udp_listener()
        
        
    def run_udp_listener(self):
        """Цикл получения данных по UDP"""
        while rclpy.ok():
            try:
                
                data, addr = self.sock.recvfrom(1024)  # Получаем пакет
                decoded_data = data.decode().strip()  # Декодируем строку
                self.get_logger().info(f"Received from {addr}: {decoded_data}")
                self.process_data(decoded_data)
                
                self.timeout_logged = False

            except socket.timeout:
                if not self.timeout_logged:
                    self.get_logger().warn("UDP Receive Error: timed out")  # Логируем только ОДИН раз
                    self.timeout_logged = True  # Устанавливаем флаг, чтобы больше не логировать
            except Exception as e:
                self.get_logger().error(f"UDP Receive Error: {e}")
            
    def process_data(self, decoded_data):
        """Парсит строку и отправляет данные в ROS 2"""
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
        """Публикует данные в ROS 2"""
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
