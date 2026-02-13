#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int main() {
    std::stack<std::string> history_back;
    std::stack<std::string> history_forward;
    std::string current = "home.com";

    std::cout << "=== Симулятор навигации браузера ===" << std::endl;
    std::cout << "Текущая страница: " << current << std::endl;
    std::cout << "Доступные команды:" << std::endl;
    std::cout << "  visit <url>  - перейти на новую страницу" << std::endl;
    std::cout << "  back         - вернуться назад" << std::endl;
    std::cout << "  forward      - перейти вперёд" << std::endl;
    std::cout << "  current      - показать текущую страницу" << std::endl;
    std::cout << "  exit         - завершить работу" << std::endl << std::endl;

    std::string command;
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, command);
        if (command.empty()) continue;

        if (command == "exit") {
            break;
        } else if (command == "current") {
            std::cout << "🌐 Текущая страница: " << current << std::endl;
        } else if (command == "back") {
            if (history_back.empty()) {
                std::cout << "⚠️  Невозможно вернуться назад (история пуста)" << std::endl;
            } else {
                history_forward.push(current);
                current = history_back.top();
                history_back.pop();
                std::cout << "⬅️  Вернулись назад на: " << current << std::endl;
            }
        } else if (command == "forward") {
            if (history_forward.empty()) {
                std::cout << "⚠️  Невозможно перейти вперёд (нет сохранённых страниц)" << std::endl;
            } else {
                history_back.push(current);
                current = history_forward.top();
                history_forward.pop();
                std::cout << "➡️  Перешли вперёд на: " << current << std::endl;
            }
        } else if (command.substr(0, 5) == "visit") {
            std::string url = command.substr(6);
            if (url.empty()) {
                std::cout << "❌ Укажите URL после команды 'visit'" << std::endl;
                continue;
            }

            while (!history_forward.empty()) history_forward.pop();
            
            history_back.push(current);
            current = url;
            std::cout << "✅ Перешли на: " << current << std::endl;
        } else {
            std::cout << "❌ Неизвестная команда. Доступные: visit, back, forward, current, exit" << std::endl;
        }

    }

    std::cout << "\n✅ Сессия завершена. Финальная страница: " << current << std::endl;
    return 0;
}