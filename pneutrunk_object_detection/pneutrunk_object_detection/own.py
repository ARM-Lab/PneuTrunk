import cv2
import numpy as np
import pyrealsense2 as rs

# Function to initialize RealSense cameras
def initialize_cameras():
    pipeline_left = rs.pipeline()
    config_left = rs.config()
    config_left.enable_device('213322072957')
    pipeline_left.start(config_left)

    pipeline_right = rs.pipeline()
    config_right = rs.config()
    config_right.enable_device('213322073438')
    pipeline_right.start(config_right)

    return pipeline_left, pipeline_right

# Function to capture frames from RealSense cameras
def capture_frames(pipeline_left, pipeline_right):
    frames_left = pipeline_left.wait_for_frames()
    frames_right = pipeline_right.wait_for_frames()

    color_frame_left = frames_left.get_color_frame()
    depth_frame_left = frames_left.get_depth_frame()

    color_frame_right = frames_right.get_color_frame()
    depth_frame_right = frames_right.get_depth_frame()

    return color_frame_left, depth_frame_left, color_frame_right, depth_frame_right

# Function to detect a ball in the depth frame
def detect_ball(depth_frame, ball_radius):
    # Implement your ball detection algorithm using the depth information
    # You may want to use techniques like thresholding, contour detection, etc.

    # Example: Thresholding based on depth values
    threshold_value = 1000  # Adjust this value based on your environment
    _, thresholded = cv2.threshold(depth_frame.get_data(), threshold_value, 255, cv2.THRESH_BINARY)

    # Find contours of the ball
    contours, _ = cv2.findContours(thresholded, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        # Check if the contour area corresponds to a ball
        if cv2.contourArea(contour) > ball_radius:
            # Implement further processing if needed
            return True

    return False

# Main function
def main():
    ball_radius = 20  # Adjust this value based on the size of the ball in your environment
    pipeline_left, pipeline_right = initialize_cameras()
    
    try:
        while True:
            color_frame_left, depth_frame_left, color_frame_right, depth_frame_right = capture_frames(pipeline_left, pipeline_right)

            ball_detected_left = detect_ball(depth_frame_left, ball_radius)
            ball_detected_right = detect_ball(depth_frame_right, ball_radius)

            if ball_detected_left and ball_detected_right:
                print("Ball detected in 3D space!")

    except KeyboardInterrupt:
        pass
    finally:
        # Stop the camera pipelines
        pipeline_left.stop()
        pipeline_right.stop()

if __name__ == "__main__":
    main()
