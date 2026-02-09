try:
    num1 = float(input("Введите первое число: "))
    num2 = float(input("Введите второе число: "))
    operation = input("Введите операцию (+, -, *, /): ").strip()
    
    if operation == '+':
        result = num1 + num2
    elif operation == '-':
        result = num1 - num2
    elif operation == '*':
        result = num1 * num2
    elif operation == '/':
        if num2 == 0:
            print("❌ Ошибка: деление на ноль!")
            sys.exit()
        result = num1 / num2
    else:
        print("❌ Ошибка: неверная операция! Допустимые операции: +, -, *, /")
        sys.exit()
    
    print(f"✅ Результат: {num1} {operation} {num2} = {result:.2f}")
except ValueError:
    print("❌ Ошибка: введите корректные числа!")
except KeyboardInterrupt:
    print("\nвыxoд из программы.")