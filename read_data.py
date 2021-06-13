import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
A0 = []
A1 = []
A2 = []
A3 = []


arduino = serial.Serial('COM5', 9600)


def plot_data(i):
    data = arduino.readline()
    data = data.rstrip()
    data = data.decode('utf-8')

    parsed_data = data.split(',')
    
    A0.append(float(parsed_data[0]))
    A1.append(float(parsed_data[1]))
    A2.append(float(parsed_data[2]))
    A3.append(float(parsed_data[3]))
    
    ax.clear()
    
    ax.plot(A0)
    ax.plot(A1)
    ax.plot(A2)
    ax.plot(A3)

    plt.ylabel('Volts (V)')

ani = animation.FuncAnimation(fig, plot_data, interval=1000)
plt.show()
