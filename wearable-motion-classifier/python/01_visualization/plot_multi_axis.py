import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../../data/raw/walking.csv")

plt.figure(figsize=(10, 6))

plt.plot(df["ax"], label="AX")
plt.plot(df["ay"], label="AY")
plt.plot(df["az"], label="AZ")

plt.title("Accelerometer Multi-Axis Signal")
plt.xlabel("Sample")
plt.ylabel("Acceleration")

plt.legend()
plt.grid(True)

plt.show()