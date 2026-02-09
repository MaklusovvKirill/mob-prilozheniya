try:
    year = int(input("Введите год: "))
    if year < 1:
        print("❌ Ошибка: год должен быть положительным!")
    elif (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(f"✅ {year} — високосный год")
    else:
        print(f"❌ {year} — невисокосный год")
except ValueError:
    print("❌ Ошибка: введите корректное целое число!")