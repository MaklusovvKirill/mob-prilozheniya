try:
    a = float(input("Введите сторону A: "))
    b = float(input("Введите сторону B: "))
    c = float(input("Введите сторону C: "))
    
    if a <= 0 or b <= 0 or c <= 0:
        print("❌ Ошибка: стороны должны быть положительными!")
        exit()

    if a + b <= c or a + c <= b or b + c <= a:
        print("❌ Такой треугольник не существует!")
        exit()
    
    types = []
    if a == b == c:
        types.append("равносторонний")
    elif a == b or b == c or a == c:
        types.append("равнобедренный")
    else:
        types.append("разносторонний")
    
    sides = sorted([a, b, c])
    if abs(sides[0]**2 + sides[1]**2 - sides[2]**2) < 1e-7:
        types.append("прямоугольный")
    
    print(f"✅ Треугольник существует и является: {', '.join(types)}")
except ValueError:
    print("❌ Ошибка: введите корректные числа!")