import random

choices = ['камень', 'ножницы', 'бумага']
computer = random.choice(choices)

user = input("Ваш ход (камень, ножницы, бумага): ").lower().strip()
if user not in choices:
    print("❌ Ошибка: выберите камень, ножницы или бумагу!")
    exit()

print(f"Компьютер выбрал: {computer}")

if user == computer:
    result = "Ничья!"
elif (
    (user == 'камень' and computer == 'ножницы') or
    (user == 'ножницы' and computer == 'бумага') or
    (user == 'бумага' and computer == 'камень')
):
    result = "✅ Вы победили!"
else:
    result = "❌ Вы проиграли!"

print(result)