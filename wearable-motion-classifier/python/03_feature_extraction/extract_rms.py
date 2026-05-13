import pandas as pd
import numpy as np

df = pd.read_csv("../../data/raw/walking.csv")

rms = np.sqrt(np.mean(df["ax"]**2))

print("AX RMS:", rms)