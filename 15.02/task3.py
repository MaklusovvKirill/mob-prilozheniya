import random
n,m=3,4; mx=[[-50+random.randint(0,100) for _ in range(m)] for _ in range(n)]
flat=[(mx[i][j],i,j) for i in range(n) for j in range(m)]
mn=min(flat); mxv=max(flat)
pos=sum(1 for v,_,_ in flat if v>0); neg=sum(1 for v,_,_ in flat if v<0); zero=sum(1 for v,_,_ in flat if v==0)
print("Матрица:\n"+"\n".join(str(row) for row in mx))
print(f"min={mn[0]}@({mn[1]},{mn[2]}), max={mxv[0]}@({mxv[1]},{mxv[2]})")
print(f"+:{pos}, -:{neg}, 0:{zero}")
