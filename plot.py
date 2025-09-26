import pandas as pd
import matplotlib.pyplot as plt
#read the runtime info file
df = pd.read_csv("./result.csv")
#group by 3 insert & delete ways
for testmode in df["TestMode"].unique():
    subset = df[df["TestMode"] == testmode]
    
    plt.figure(figsize=(8,6))
    for tree in subset["TreeType"].unique():
        tree_data = subset[subset["TreeType"] == tree]
        plt.plot(tree_data["N"], tree_data["Runtime(ms)"], marker="o", label=tree)
    #the figures of the plot
    plt.xlabel("Input Size N")
    plt.ylabel("Runtime (milliseconds)")
    plt.title(f"Performance Comparison of Trees ({testmode})")
    plt.legend()
    plt.grid(True)
    plt.show() 