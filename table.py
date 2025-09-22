import pandas as pd
#read the runtime file
df = pd.read_csv("result.csv")
#group by 3 insert & delete ways
for testmode in df["TestMode"].unique():
    print(f"\nRuntime Table for {testmode}")
    table = df[df["TestMode"] == testmode].pivot(index="N", columns="TreeType", values="Runtime(ms)")
    print(table.round(6))