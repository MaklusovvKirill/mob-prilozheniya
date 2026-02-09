try:
    amount = float(input("Введите сумму покупки (руб): "))
    if amount < 0:
        print("❌ Ошибка: сумма не может быть отрицательной!")
        exit()
    
    has_card = input("Есть карта лояльности? (да/нет): ").lower().strip() == 'да'
    is_holiday = input("Сегодня праздничный день? (да/нет): ").lower().strip() == 'да'
    
    discount = 0.0
    
    if amount > 1000:
        discount += 5.0
    
    if has_card:
        discount += 3.0
    
    if is_holiday:
        discount += 2.0
    
    discount = min(discount, 15.0)
    final_amount = amount * (1 - discount / 100)
    
    print(f"\n💰 Сумма покупки: {amount:.2f} руб")
    print(f"📉 Скидка: {discount:.1f}%")
    print(f"💵 Итого к оплате: {final_amount:.2f} руб")
except ValueError:
    print("❌ Ошибка: введите корректное число!")