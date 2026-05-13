import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../../data/raw/walking.csv")

plt.plot(df["ax"])
plt.title("Accelerometer X Axis")
plt.xlabel("Sample")
plt.ylabel("Acceleration")

plt.show()