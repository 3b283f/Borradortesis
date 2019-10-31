"""
Lorenz attractor (Runge-Kutta method)
"""
import sys
import traceback
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
def rungekutta(ci,h,STEP=50):
# Condicionese Iniciales
# F inicial usando Condiciones Iniciales
    salida = [[],[],[]]
    xyz = ci
    for _ in range(STEP):
        k_0= lorenz(xyz)
        k_1 = lorenz([x + k * h / 2 for x, k in zip(xyz, k_0)])
        k_2 = lorenz([x + k * h / 2 for x, k in zip(xyz, k_1)])
        k_3 = lorenz([x + k * h for x, k in zip(xyz, k_2)])

        for i in range(3):
            xyz[i] += (k_0[i] + 2 * k_1[i] + 2 * k_2[i] + k_3[i])* h / 6.0
            salida[i].append(xyz[i])

    return salida

def grafica(data):
    """ Protting """
    try:
        fig = plt.figure()
        ax = Axes3D(fig)
        ax.set_xlabel("x")
        ax.set_ylabel("y")
        ax.set_zlabel("z")
        ax.set_title("Lorenz attractor (Runge-Kutta method)")
        ax.plot(data[0], data[1], data[2], color="red", lw=1)
        #plt.show()
        plt.savefig("runge_kutta.png")
    except Exception as e:
        raise

def lorenz(xyz, p=10, r=28, b=8/3.0):
    try:
        return [
            -p * xyz[0] + p * xyz[1],
            -xyz[0] * xyz[2] + r * xyz[0] - xyz[1],
            xyz[0] * xyz[1] - b * xyz[2]
            ]
    except Exception as e:
        raise

### Programa Principal

datos = rungekutta([1,2,3],0.003,100000)
grafica(datos)
#print(datos)
