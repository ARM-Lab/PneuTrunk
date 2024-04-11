import pyrealsense2 as rs

def get_serial_number():
    context = rs.context()
    devices = context.query_devices()

    for device in devices:
        serial_number = device.get_info(rs.camera_info.serial_number)
        print(f"Serial Number: {serial_number}")

if __name__ == "__main__":
    get_serial_number()
