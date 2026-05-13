import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv("../../data/raw/walking.csv")

signal = df["ax"].values

fft_values = np.fft.fft(signal)
magnitude = np.abs(fft_values)

plt.plot(magnitude)
plt.title("FFT Magnitude Spectrum")
plt.show()