import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("info.csv")
algo1 = df[df["Algorithm"]==1]
algo2 = df[df["Algorithm"]==2]
algo3 = df[df["Algorithm"]==3]
algo4 = df[df["Algorithm"]==4]
fig, axes = plt.subplots(nrows=2, ncols=4, figsize=(5, 3))
axes[0][0].plot(algo1["Size"],algo1["Duration"])
axes[0][1].plot(algo2["Size"],algo2["Duration"])
axes[0][2].plot(algo3["Size"],algo3["Duration"])
axes[0][3].plot(algo4["Size"],algo4["Duration"])
axes[1][0].plot(algo1["Size"],algo1["Comparisons"])
axes[1][1].plot(algo2["Size"],algo2["Comparisons"])
axes[1][2].plot(algo3["Size"],algo3["Comparisons"])
axes[1][3].plot(algo4["Size"],algo4["Comparisons"])
#fig.tight_layout()
plt.show()