#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> lines;
    std::string input;

    std::cout << "=== Текстовый редактор (введите 'exit' для выхода) ===" << std::endl;
    std::cout << "Подсказка: пустая строка = отмена последнего действия" << std::endl << std::endl;

    while (true) {
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        } else if (input.empty()) {
            if (!lines.empty()) {
                lines.pop_back();
                std::cout << "[Undo выполнено]" << std::endl;
            } else {
                std::cout << "[Нечего отменять]" << std::endl;
            }
        } else {
            lines.push_back(input);
        }

        if (lines.empty()) {
            std::cout << "(пусто)" << std::endl;
        } else {
            bool first = true;
            for (const auto& line : lines) {
                if (!first) std::cout << " | ";
                std::cout << line;
                first = false;
            }
            std::cout << std::endl;
        }
        std::cout << "------------------------" << std::endl;
    }

    std::cout << "\n✅ Редактор закрыт. Итоговый текст:" << std::endl;
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    return 0;
}