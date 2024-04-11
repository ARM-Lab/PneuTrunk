import numpy as np
import math
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# =========================================================
# ================== Forward Kinematics ===================
# =========================================================
def forward_kinematics(q):
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
    q = np.zeros(13)
    effectorZ = forward_kinematics(q)
    print(effectorZ)

if __name__ == "__main__":
    main()