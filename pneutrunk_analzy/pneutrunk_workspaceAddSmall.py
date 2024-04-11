import numpy as np
import math
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

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

        #navyse small
        A20210 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T021 = np.dot(T024, A20210)
        A21220 = [[math.cos(math.radians(q[13])), 0, math.sin(math.radians(q[13])), 0], [0, 1, 0, 0], [-math.sin(math.radians(q[13])), 0, math.cos(math.radians(q[13])), 0], [0, 0, 0, 1]]
        A22230 = [[1, 0, 0, 0], [0, math.cos(math.radians(q[14])), -math.sin(math.radians(q[14])), 0], [0, math.sin(math.radians(q[14])), math.cos(math.radians(q[14])), 0], [0, 0, 0, 1]]
        A23240 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, r2], [0, 0, 0, 1]]
        T0240 = np.dot(np.dot(np.dot(np.dot(T024, A20210), A21220), A22230), A23240)

        A2425 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 3*r2 + q[12]], [0, 0, 0, 1]]
        T025 = np.dot(T0240, A2425)
        #result = np.reshape(T025, -1)
        result = T025
        return result

def main(args=None):
    print("Workspace...")
    incrementRot = 40
    minRot = -20
    maxRot = 21
    incrementLin = 10
    i = 0
    q = np.zeros(15)
    x = []
    y = []
    z = []

    for q[0] in range(minRot,maxRot,incrementRot):
        for q[1] in range(minRot,maxRot,incrementRot):
             for q[2] in range(minRot,maxRot,incrementRot):
                  for q[3] in range(minRot,maxRot,incrementRot):
                    for q[4] in range(minRot,maxRot,incrementRot):
                            for q[5] in range(minRot,maxRot,incrementRot):
                                for q[6] in range(minRot,maxRot,incrementRot):
                                    for q[7] in range(minRot,maxRot,incrementRot):
                                        for q[8] in range(minRot,maxRot,incrementRot):
                                            for q[9] in range(minRot,maxRot,incrementRot):
                                                for q[10] in range(minRot,maxRot,incrementRot):
                                                    for q[11] in range(minRot,maxRot,incrementRot):
                                                        for q[13] in range(minRot,maxRot,incrementRot):
                                                            for q[14] in range(minRot,maxRot,incrementRot):
                                                                for q[12] in range(0,11,incrementLin):
                                                                    result = forward_kinematics(q)
                                                                    x.append(result[0][3])
                                                                    y.append(result[1][3])
                                                                    z.append(result[2][3])
                                                                    print(q)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(x, y, z)
    plt.show()

if __name__ == "__main__":
    main()