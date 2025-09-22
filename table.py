import pandas as pd

df = pd.read_csv("result.csv")

for testmode in df["TestMode"].unique():
    print(f"\nRuntime Table for {testmode}")
    table = df[df["TestMode"] == testmode].pivot(index="N", columns="TreeType", values="Runtime(ms)")
    print(table.round(6))