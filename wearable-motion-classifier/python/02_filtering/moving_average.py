import pandas as pd

WINDOW_SIZE = 5

df = pd.read_csv("../../data/raw/walking.csv")

df["ax_filtered"] = (
    df["ax"]
    .rolling(WINDOW_SIZE)
    .mean()
)

print(df.head())