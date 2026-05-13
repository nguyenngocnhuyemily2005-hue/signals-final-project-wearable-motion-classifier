import pandas as pd
import numpy as np

df = pd.read_csv("../../data/raw/walking.csv")

variance = np.var(df["ax"])

print("AX Variance:", variance)