#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> supportQueue;

    supportQueue.push("Проблема с оплатой");
    supportQueue.push("Не работает авторизация");
    supportQueue.push("Ошибка при загрузке файла");
    supportQueue.push("Вопрос по тарифу");

    while (!supportQueue.empty()) {
        std::string call = supportQueue.front();
        supportQueue.pop();
        std::cout << "Обработка: " << call << std::endl;
    }

    std::cout << "Очередь пуста? " << (supportQueue.empty() ? "true" : "false") << std::endl;
    std::cout << "Размер очереди: " << supportQueue.size() << std::endl;

    return 0;
}
