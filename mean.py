import os
fpath = os.path.dirname(__file__)
file = os.path.join(fpath, "Error.csv")

with open(file) as f:
    data = f.readlines()
d = list(map(float, data[0].split(',')))
d = d[900:]
print(sum(d) / 100)