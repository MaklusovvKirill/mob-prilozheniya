def add(a, b):
    return a + b


def subtract(a, b):
    return a - b


def multiply(a, b):
    return a * b


def divide(a, b):
    if b == 0:
        raise ValueError("Ошибка: деление на ноль!")
    return a / b


def power(a, b):
    return a ** b


def get_operation_name(symbol):
    operations = {
        '+': 'сложение',
        '-': 'вычитание',
        '*': 'умножение',
        '/': 'деление',
        '**': 'возведение в степень',
        '^': 'возведение в степень'
    }
    return operations.get(symbol, 'неизвестная операция')


def calculate(operation, a, b):
    operations = {
        '+': add,
        '-': subtract,
        '*': multiply,
        '/': divide,
        '**': power,
        '^': power
    }

    if operation not in operations:
        raise ValueError(f"Неизвестная операция: {operation}")

    return operations[operation](a, b)


def calculator_interface():
    print("=" * 40)
    print("КАЛЬКУЛЯТОР")
    print("=" * 40)
    print("Доступные операции: +, -, *, /, ** или ^")
    print("Для выхода введите 'q'\n")

    while True:
        try:
            user_input = input("Введите выражение (например, 5 + 3): ").strip()

            if user_input.lower() == 'q':
                print("Выход из калькулятора. До свидания!")
                break

            parts = user_input.split()
            if len(parts) != 3:
                print("Ошибка")
                continue

            a, op, b = parts[0], parts[1], parts[2]

            a = float(a)
            b = float(b)

            result = calculate(op, a, b)
            op_name = get_operation_name(op)

            print(f"\nРезультат {op_name}: {a} {op} {b} = {result:.4f}\n")

        except ValueError as e:
            print(f"Ошибка: {e}\n")
        except Exception as e:
            print(f"Неожиданная ошибка: {e}\n")


def test_calculator():
    """Тестирование всех функций калькулятора"""
    print("\nТестирование калькулятора:")
    print("-" * 40)

    test_cases = [
        ('+', 5, 3, 8),
        ('-', 10, 4, 6),
        ('*', 7, 6, 42),
        ('/', 20, 5, 4),
        ('**', 2, 3, 8),
        ('^', 3, 2, 9)
    ]

    for op, a, b, expected in test_cases:
        result = calculate(op, a, b)
        status = "✓" if abs(result - expected) < 0.0001 else "✗"
        print(f"{status} {a} {op} {b} = {result} (ожидалось {expected})")

    try:
        divide(5, 0)
        print("✗ Тест деления на ноль провален")
    except ValueError:
        print("✓ Тест деления на ноль пройден")

    print("-" * 40)


if __name__ == "__main__":
    test_calculator()
    calculator_interface()
