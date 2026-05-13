import pandas as pd
import matplotlib.pyplot as plt
from scipy.signal import butter, filtfilt

# Load CSV
df = pd.read_csv("../../data/raw/walking.csv")

# Sampling rate
fs = 100

# Cutoff frequency
cutoff = 5

# Butterworth low-pass filter
b, a = butter(
    N=4,
    Wn=cutoff / (fs / 2),
    btype='low'
)

# Filter AX signal
filtered_ax = filtfilt(b, a, df["ax"])

# Plot comparison
plt.figure(figsize=(10, 6))

plt.plot(df["ax"], label="Raw AX")
plt.plot(filtered_ax, label="Filtered AX")

plt.title("Low-Pass Filter Result")
plt.xlabel("Sample")
plt.ylabel("Acceleration")

plt.legend()
plt.grid(True)

plt.show()