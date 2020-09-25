import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import os

def Plot_Graph(file):
    sample = list()
    with open(file) as f:
        data = f.readlines()
    for s in data:
        sample += [list(map(float, s.split(',')))]
    x = [a[0] for a in sample]
    y = [a[1] for a in sample]
    z = [a[2] for a in sample]
    
    fig = plt.figure()
    ax = Axes3D(fig)

    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("F(x, y)")
    ax.scatter3D(x, y, z, c = z,cmap="jet")
    plt.show()

def Show_Error(file):
    with open(file) as f:
        data = f.readlines()
    y = list(map(float, data[0].split(',')))
    x = range(1, len(y) + 1)
    
    plt.plot(x, y)
    plt.xlabel("Step")
    plt.ylabel("Error")
    plt.show()

def main():
    fpath = os.path.dirname(__file__)
    Plot_Graph(os.path.join(fpath, "Graph.csv"))
    Show_Error(os.path.join(fpath, "Error.csv"))


if __name__ == "__main__":
    main()