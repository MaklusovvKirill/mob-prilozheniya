n = int(input("N="))
print("Единичная:\n", "\n".join(" ".join("1" if i==j else "0" for j in range(n)) for i in range(n)))
print("Последовательная:\n", "\n".join(" ".join(str(i*n+j+1) for j in range(n)) for i in range(n)))
print("Шахматная:\n", "\n".join(" ".join(str((i+j)%2) for j in range(n)) for i in range(n)))
