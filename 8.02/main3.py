try:
    hour = int(input("Введите текущий час (0-23): "))
    if hour < 0 or hour > 23:
        print("❌ Ошибка: час должен быть в диапазоне 0-23!")
    elif 0 <= hour <= 5:
        print("✅ Сейчас: Ночь")
    elif 6 <= hour <= 11:
        print("✅ Сейчас: Утро")
    elif 12 <= hour <= 17:
        print("✅ Сейчас: День")
    else:  # 18-23
        print("✅ Сейчас: Вечер")
except ValueError:
    print("❌ Ошибка: введите корректное целое число!")