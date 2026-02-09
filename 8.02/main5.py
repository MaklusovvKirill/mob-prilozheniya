scales = {'C': 'Цельсий', 'F': 'Фаренгейт', 'K': 'Кельвин'}

from_scale = input("Из какой шкалы конвертировать (C, F, K): ").upper().strip()
to_scale = input("В какую шкалу конвертировать (C, F, K): ").upper().strip()

if from_scale not in scales or to_scale not in scales:
    print("❌ Ошибка: допустимые шкалы — C, F, K")
    exit()

try:
    temp = float(input(f"Введите температуру в {scales[from_scale]}: "))
    
    if from_scale == 'C':
        k = temp + 273.15
    elif from_scale == 'F':
        k = (temp - 32) * 5/9 + 273.15
    else:  # K
        k = temp
    
    if to_scale == 'C':
        result = k - 273.15
    elif to_scale == 'F':
        result = (k - 273.15) * 9/5 + 32
    else:  # K
        result = k
    
    print(f"✅ {temp}°{from_scale} = {result:.2f}°{to_scale}")
except ValueError:
    print("❌ Ошибка: введите корректное число!")