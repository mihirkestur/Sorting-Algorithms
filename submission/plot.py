import pandas as pd
import matplotlib.pyplot as plt
bt = pd.read_csv("bubble_time.csv",header=None)
bc = pd.read_csv("bubble_comp.csv",header=None)
st = pd.read_csv("selection_time.csv",header=None)
sc = pd.read_csv("selection_comp.csv",header=None)
mt = pd.read_csv("merge_time.csv",header=None)
mc = pd.read_csv("merge_comp.csv",header=None)
qt = pd.read_csv("quick_time.csv",header=None)
qc = pd.read_csv("quick_comp.csv",header=None)


fig, axes = plt.subplots(nrows=2, ncols=4, figsize=(5, 3))
axes[0][0].plot(bt[0],bt[1])
axes[0][1].plot(st[0],st[1])
axes[0][2].plot(mt[0],mt[1])
axes[0][3].plot(qt[0],qt[1])
axes[1][0].plot(bc[0],bc[1])
axes[1][1].plot(sc[0],sc[1])
axes[1][2].plot(mc[0],mc[1])
axes[1][3].plot(qc[0],qc[1])
#fig.tight_layout()
plt.show()
