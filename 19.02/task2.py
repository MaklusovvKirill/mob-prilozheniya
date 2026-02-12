import random
import json
import os
from datetime import datetime

LEADERBOARD_FILE = "leaderboard.json"


def generate_number(min_val, max_val):
    """Генерирует случайное число в диапазоне [min_val, max_val]"""
    return random.randint(min_val, max_val)


def get_hint(number, guess):
    """Дает подсказку: больше или меньше загаданное число"""
    if guess < number:
        return "Загаданное число БОЛЬШЕ"
    elif guess > number:
        return "Загаданное число МЕНЬШЕ"
    else:
        return "ПОЗДРАВЛЯЕМ! Вы угадали!"


def calculate_score(attempts, max_attempts, difficulty):
    """Вычисляет очки на основе попыток и сложности"""
    base_score = max(10, (max_attempts - attempts + 1) * 10)

    difficulty_multipliers = {
        'легкий': 1.0,
        'средний': 1.5,
        'сложный': 2.0,
        'эксперт': 3.0
    }

    multiplier = difficulty_multipliers.get(difficulty.lower(), 1.0)
    final_score = int(base_score * multiplier)

    return max(final_score, 10)


def load_leaderboard():
    """Загружает таблицу лидеров из файла"""
    if os.path.exists(LEADERBOARD_FILE):
        try:
            with open(LEADERBOARD_FILE, 'r', encoding='utf-8') as f:
                return json.load(f)
        except:
            return []
    return []


def save_leaderboard(leaderboard):
    """Сохраняет таблицу лидеров в файл"""
    with open(LEADERBOARD_FILE, 'w', encoding='utf-8') as f:
        json.dump(leaderboard, f, ensure_ascii=False, indent=2)


def save_game_result(player_name, score, difficulty):
    """Сохраняет результат игры в таблицу лидеров"""
    leaderboard = load_leaderboard()

    record = {
        "player": player_name,
        "score": score,
        "difficulty": difficulty,
        "date": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    }

    leaderboard.append(record)
    leaderboard.sort(key=lambda x: x['score'], reverse=True)
    leaderboard = leaderboard[:10]

    save_leaderboard(leaderboard)
    return record


def show_leaderboard():
    """Показывает таблицу лидеров"""
    leaderboard = load_leaderboard()

    if not leaderboard:
        print("\nТаблица лидеров пуста. Станьте первым игроком!\n")
        return

    print("\n" + "=" * 60)
    print("ТАБЛИЦА ЛИДЕРОВ")
    print("=" * 60)
    print(f"{'Место':<6} {'Игрок':<20} {'Очки':<10} {'Сложность':<12} {'Дата':<20}")
    print("-" * 60)

    for idx, record in enumerate(leaderboard, 1):
        print(f"{idx:<6} {record['player']:<20} {record['score']:<10} "
              f"{record['difficulty']:<12} {record['date']:<20}")

    print("=" * 60 + "\n")


def show_statistics(games_history):
    """Показывает статистику игр"""
    if not games_history:
        print("\nСтатистика пуста. Сыграйте хотя бы одну игру!\n")
        return

    total_games = len(games_history)
    wins = sum(1 for g in games_history if g['won'])
    total_attempts = sum(g['attempts'] for g in games_history)
    avg_attempts = total_attempts / total_games

    print("\n" + "=" * 50)
    print("СТАТИСТИКА ИГРОКА")
    print("=" * 50)
    print(f"Всего игр:       {total_games}")
    print(f"Побед:           {wins} ({wins/total_games*100:.1f}%)")
    print(f"Поражений:       {total_games - wins}")
    print(f"Всего попыток:   {total_attempts}")
    print(f"Средне попыток:  {avg_attempts:.1f}")

    difficulties = {}
    for game in games_history:
        diff = game['difficulty']
        difficulties[diff] = difficulties.get(diff, 0) + 1

    print("\nИгры по сложности:")
    for diff, count in sorted(difficulties.items()):
        print(f"  {diff.capitalize()}: {count}")

    print("=" * 50 + "\n")


def play_game(difficulty='легкий'):
    """
    Основная функция игры.
    Возвращает словарь с результатами игры.
    """
    difficulty_settings = {
        'легкий': {'min': 1, 'max': 50, 'max_attempts': 10},
        'средний': {'min': 1, 'max': 100, 'max_attempts': 7},
        'сложный': {'min': 1, 'max': 200, 'max_attempts': 5},
        'эксперт': {'min': 1, 'max': 500, 'max_attempts': 4}
    }

    settings = difficulty_settings.get(difficulty.lower(), difficulty_settings['легкий'])
    min_val, max_val, max_attempts = settings['min'], settings['max'], settings['max_attempts']

    secret_number = generate_number(min_val, max_val)
    attempts = 0
    won = False

    print(f"\n🎮 Угадайте число от {min_val} до {max_val}!")
    print(f"У вас есть {max_attempts} попыток.\n")

    while attempts < max_attempts:
        try:
            guess = int(input(f"Попытка {attempts + 1}/{max_attempts}. Ваш вариант: "))
            attempts += 1

            if guess < min_val or guess > max_val:
                print(f"Число должно быть в диапазоне от {min_val} до {max_val}!\n")
                attempts -= 1
                continue

            hint = get_hint(secret_number, guess)
            print(f"💡 {hint}\n")

            if guess == secret_number:
                won = True
                break

        except ValueError:
            print("Ошибка: введите целое число!\n")

    if won:
        score = calculate_score(attempts, max_attempts, difficulty)
        print(f"🏆 ПОБЕДА! Вы угадали за {attempts} попыток!")
        print(f"Ваш счет: {score} очков\n")
    else:
        score = 0
        print(f"😞 ПОРАЖЕНИЕ! Загаданное число было: {secret_number}\n")

    return {
        'won': won,
        'attempts': attempts,
        'secret_number': secret_number,
        'difficulty': difficulty,
        'score': score
    }


def game_menu():
    """Главное меню игры"""
    games_history = []
    player_name = input("Введите ваше имя: ").strip() or "Игрок"

    while True:
        print("\n" + "=" * 50)
        print(f"🎮 ИГРА 'УГАДАЙ ЧИСЛО' | Игрок: {player_name}")
        print("=" * 50)
        print("1. Новая игра (Легкий уровень)")
        print("2. Новая игра (Средний уровень)")
        print("3. Новая игра (Сложный уровень)")
        print("4. Новая игра (Экспертный уровень)")
        print("5. Показать статистику")
        print("6. Таблица лидеров")
        print("7. Сменить имя игрока")
        print("0. Выход")
        print("=" * 50)

        choice = input("Выберите действие: ").strip()

        if choice == '0':
            print("\nСпасибо за игру! До свидания!\n")
            break

        elif choice == '1':
            result = play_game('легкий')
            games_history.append(result)
            if result['won']:
                save_game_result(player_name, result['score'], 'легкий')

        elif choice == '2':
            result = play_game('средний')
            games_history.append(result)
            if result['won']:
                save_game_result(player_name, result['score'], 'средний')

        elif choice == '3':
            result = play_game('сложный')
            games_history.append(result)
            if result['won']:
                save_game_result(player_name, result['score'], 'сложный')

        elif choice == '4':
            result = play_game('эксперт')
            games_history.append(result)
            if result['won']:
                save_game_result(player_name, result['score'], 'эксперт')

        elif choice == '5':
            show_statistics(games_history)

        elif choice == '6':
            show_leaderboard()

        elif choice == '7':
            player_name = input("Введите новое имя: ").strip() or player_name
            print(f"Имя изменено на: {player_name}")

        else:
            print("Неверный выбор. Попробуйте снова.\n")


if __name__ == "__main__":
    game_menu()
