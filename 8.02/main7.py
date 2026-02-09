try:
    height = float(input("Введите рост в метрах: "))
    weight = float(input("Введите вес в кг: "))
    
    if height <= 0 or weight <= 0:
        print("❌ Ошибка: рост и вес должны быть положительными!")
    else:
        bmi = weight / (height ** 2)
        
        if bmi < 18.5:
            category = "Недостаточный вес"
        elif bmi < 25:
            category = "Нормальный вес"
        elif bmi < 30:
            category = "Избыточный вес"
        else:
            category = "Ожирение"
        
        print(f"✅ ИМТ: {bmi:.1f} — {category}")
except ValueError:
    print("❌ Ошибка: введите корректные числа!")