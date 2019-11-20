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

def rungekutta2(ci,h,STEP=50):
# Condicionese Iniciales
# F inicial usando Condiciones Iniciales
    salida = [[],[],[]]
    xyz = ci
    for _ in range(STEP):
        k_0 = LP(xyz)
        k_1 = LP([x + k * h / 2 for x, k in zip(xyz, k_0)])
        k_2 = LP([x + k * h / 2 for x, k in zip(xyz, k_1)])
        k_3 = LP([x + k * h for x, k in zip(xyz, k_2)])

        for i in range(3):
            xyz[i] += (k_0[i] + 2 * k_1[i] + 2 * k_2[i] + k_3[i])* h / 6.0
            salida[i].append(xyz[i])

    return salida




def grafica(data,titulo):
    """ Protting """
    try:
        fig = plt.figure()
        ax = Axes3D(fig)
        ax.set_xlabel("x")
        ax.set_ylabel("y")
        ax.set_zlabel("z")
        ax.set_title(titulo)
        ax.plot(data[0], data[1], data[2], color="red", lw=1)
        #plt.show()
        plt.savefig("runge_kutta.png")
    except Exception as e:
        raise

# Sistema dinamico lauraPetrach
def LP(y,aP=0.9):
  aIP= 0.1*aP
  aL= 3.0*aP
  bL= aP
  bP= 5.0*aP
  bIP= 10.0*aP
  GammaL=1.0
  deltaP=1.0
  AL= 2.0
  AP= -1.0

  L = y[0]
  P =y[1]
  IP=y[2]

  return [
    -aL*L + bL*P*(1-(P/GammaL)*(P/GammaL)) + bL*AP,
    -aP*P + bP*L + bP*AL/(1+deltaP*IP),
    -aIP*IP + bIP*P
    ]

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

file = open("entrada.txt","r")
#list(map(int,
datosIniciales = list(map(int,file.readline().replace("\n","").split(',')))
incremento =float(file.readline().replace("\n",""))
numDatos = int(file.readline().replace("\n",""))

print(datosIniciales,incremento,numDatos)
#datos = rungekutta2([1,2,3],0.003,100000)
datos = rungekutta2(datosIniciales,incremento,numDatos)
grafica(datos,"Laura Noze Que")
#print(datos)
