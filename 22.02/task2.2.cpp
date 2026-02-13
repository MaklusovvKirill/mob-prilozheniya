#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <sstream>

void printPlayers(const std::list<std::string>& players) {
    if (players.empty()) {
        std::cout << "(список пуст)" << std::endl;
        return;
    }
    int idx = 0;
    for (const auto& p : players) {
        std::cout << "[" << idx++ << "] " << p << std::endl;
    }
}

int main() {
    std::list<std::string> players;
    std::string command;

    std::cout << "=== Управление игроками ===" << std::endl;
    std::cout << "Доступные команды:" << std::endl;
    std::cout << "  add <имя>          - добавить в конец" << std::endl;
    std::cout << "  insert_after <A> <B> - вставить B после A" << std::endl;
    std::cout << "  remove <имя>       - удалить игрока" << std::endl;
    std::cout << "  move <имя> <N>     - переместить на N позиций (±)" << std::endl;
    std::cout << "  list               - показать список" << std::endl;
    std::cout << "  exit               - завершить программу" << std::endl << std::endl;

    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, command);
        if (command.empty()) continue;

        std::istringstream iss(command);
        std::string cmd, arg1, arg2;
        int offset = 0;
        iss >> cmd;

        if (cmd == "exit") {
            break;
        } else if (cmd == "add") {
            iss >> arg1;
            if (arg1.empty()) {
                std::cout << "❌ Укажите имя игрока" << std::endl;
            } else {
                players.push_back(arg1);
                std::cout << "✅ Игрок '" << arg1 << "' добавлен" << std::endl;
            }
        } else if (cmd == "insert_after") {
            iss >> arg1 >> arg2;
            auto it = std::find(players.begin(), players.end(), arg1);
            if (it == players.end()) {
                std::cout << "❌ Игрок '" << arg1 << "' не найден" << std::endl;
            } else if (arg2.empty()) {
                std::cout << "❌ Укажите имя для вставки" << std::endl;
            } else {
                players.insert(std::next(it), arg2);
                std::cout << "✅ Игрок '" << arg2 << "' вставлен после '" << arg1 << "'" << std::endl;
            }
        } else if (cmd == "remove") {
            iss >> arg1;
            auto it = std::find(players.begin(), players.end(), arg1);
            if (it == players.end()) {
                std::cout << "❌ Игрок '" << arg1 << "' не найден" << std::endl;
            } else {
                players.erase(it);
                std::cout << "✅ Игрок '" << arg1 << "' удалён" << std::endl;
            }
        } else if (cmd == "move") {
            iss >> arg1 >> offset;
            auto it = std::find(players.begin(), players.end(), arg1);
            if (it == players.end()) {
                std::cout << "❌ Игрок '" << arg1 << "' не найден" << std::endl;
            } else if (players.size() <= 1) {
                std::cout << "ℹ️  Перемещение невозможно (в списке <=1 игрока)" << std::endl;
            } else {
                auto target = it;
                if (offset > 0) {
                    int steps = std::min(offset + 1, static_cast<int>(std::distance(it, players.end())));
                    std::advance(target, steps);
                    players.splice(target, players, it);
                    std::cout << "✅ Игрок '" << arg1 << "' перемещён на +" << offset << " позиций" << std::endl;
                } else if (offset < 0) {
                    int steps = std::min(-offset, static_cast<int>(std::distance(players.begin(), it)));
                    std::advance(target, -steps);
                    players.splice(target, players, it);
                    std::cout << "✅ Игрок '" << arg1 << "' перемещён на " << offset << " позиций" << std::endl;
                }
            }
        } else if (cmd == "list") {
            printPlayers(players);
        } else {
            std::cout << "❌ Неизвестная команда. Доступные: add, insert_after, remove, move, list, exit" << std::endl;
        }
    }

    std::cout << "\n✅ Финальный список игроков:" << std::endl;
    printPlayers(players);

    return 0;
}