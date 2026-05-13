import pandas as pd
import numpy as np

df = pd.read_csv("../../data/raw/walking.csv")

variance = np.var(df["ax"])

if variance < 0.5:
    print("IDLE")

elif variance < 5:
    print("WALKING")

else:
    print("RUNNING")