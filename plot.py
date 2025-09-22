import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("result.csv")
testmodes = df["TestMode"].unique()

for testmode in testmodes:
    subset = df[df["TestMode"] == testmode]
    
    plt.figure(figsize=(8,6))
    for tree in subset["TreeType"].unique():
        tree_data = subset[subset["TreeType"] == tree]
        plt.plot(tree_data["N"], tree_data["Runtime(ms)"], marker="o", label=tree)
    
    plt.xlabel("Input Size N")
    plt.ylabel("Runtime (milliseconds)")
    plt.title(f"Performance Comparison of Trees ({testmode})")
    plt.legend()
    plt.grid(True)
    plt.show() 