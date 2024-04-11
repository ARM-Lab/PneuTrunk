import numpy as np

def jacobian_matrix(theta1, theta2, link_length1, link_length2):
    # Calculate the Jacobian matrix for a 2-DOF planar robot
    J = np.array([
        [-link_length1 * np.sin(theta1) - link_length2 * np.sin(theta1 + theta2), -link_length2 * np.sin(theta1 + theta2)],
        [link_length1 * np.cos(theta1) + link_length2 * np.cos(theta1 + theta2), link_length2 * np.cos(theta1 + theta2)]
    ])
    return J

def is_point_in_workspace(theta1, theta2, link_length1, link_length2, x, y):
    # Calculate the Jacobian matrix
    J = jacobian_matrix(theta1, theta2, link_length1, link_length2)

    # Calculate the end-effector position
    end_effector_position = np.array([
        link_length1 * np.cos(theta1) + link_length2 * np.cos(theta1 + theta2),
        link_length1 * np.sin(theta1) + link_length2 * np.sin(theta1 + theta2)
    ])

    # Check if the given point is within a tolerance of the end-effector position
    tolerance = 0.1
    distance = np.linalg.norm(np.array([x, y]) - end_effector_position)
    print("x,y:"+str(np.array([x, y])))
    print("end:"+str(end_effector_position))
    
    return distance < tolerance

# Example usage
theta1 = np.radians(30)  # Joint angle 1 in radians
theta2 = np.radians(45)  # Joint angle 2 in radians
link_length1 = 1.0  # Length of the first link
link_length2 = 0.8  # Length of the second link

x_check = 1.2  # X-coordinate to check
y_check = 0.5  # Y-coordinate to check

result = is_point_in_workspace(theta1, theta2, link_length1, link_length2, x_check, y_check)

if result:
    print("The point is within the dexterous workspace.")
else:
    print("The point is outside the dexterous workspace.")