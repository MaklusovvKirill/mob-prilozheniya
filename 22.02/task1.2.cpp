#include <iostream>
#include <queue>
#include <string>

struct Job {
    int id;
    std::string user;
    int pages;
};

int main() {
    std::queue<Job> printQueue;
    int toner = 30;

    printQueue.push({1, "Alice", 10});
    printQueue.push({2, "Bob", 15});
    printQueue.push({3, "Charlie", 25});
    printQueue.push({4, "Diana", 5});
    printQueue.push({5, "Eve", 8});

    std::cout << "=== Симуляция печати ===" << std::endl;
    std::cout << "Начальный запас тонера: " << toner << " страниц" << std::endl << std::endl;

    while (!printQueue.empty()) {
        Job& current = printQueue.front();
        
        if (current.pages <= toner) {
            std::cout << "Печать задания ID " << current.id 
                      << " от " << current.user 
                      << " (" << current.pages << " стр.)" << std::endl;
            toner -= current.pages;
            std::cout << "Остаток тонера: " << toner << " страниц" << std::endl;
            printQueue.pop();
        } else {
            std::cout << "\n⚠️  Не хватает тонера для задания ID: " << current.id 
                      << " (требуется " << current.pages << " стр., осталось " << toner << ")" << std::endl;
            std::cout << "Нажмите любую клавишу для дозаправки (+20 страниц)..." << std::endl;
            
            std::cin.ignore(10000, '\n');
            std::cin.get();
            
            toner += 20;
            std::cout << "Дозаправка выполнена! Новый запас тонера: " << toner << " страниц" << std::endl;
        }
        std::cout << "------------------------" << std::endl;
    }

    std::cout << "\n✅ Все задания напечатаны!" << std::endl;
    std::cout << "Финальный остаток тонера: " << toner << " страниц" << std::endl;

    return 0;
}