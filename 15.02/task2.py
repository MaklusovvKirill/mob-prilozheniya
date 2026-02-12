a = [[1,2],[3,4]]; b = [[5,6],[7,8]]; k = 3
print("Сложение:\n", "\n".join(str([a[i][j]+b[i][j] for j in range(len(a[0]))]) for i in range(len(a))))
print("Транспонирование:\n", "\n".join(str([a[j][i] for j in range(len(a))]) for i in range(len(a[0]))))
print("Умножение на", k, ":\n", "\n".join(str([x*k for x in row]) for row in a))
print("Суммы строк:", [sum(row) for row in a], "столбцов:", [sum(a[i][j] for i in range(len(a))) for j in range(len(a[0]))])
