#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool isValidBrackets(const std::string& s) {
    std::stack<char> st;
    std::unordered_map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    std::string testCases[] = {
        "({[]})",   // true
        "({[})",    // false
        "([]){}",   // true
        "([)]",     // false
        "",         // true
        "{"         // false
    };

    std::cout << "=== Проверка корректности скобочных последовательностей ===" << std::endl;
    for (const auto& test : testCases) {
        bool result = isValidBrackets(test);
        std::cout << "Ввод: \"" << test << "\" -> " 
                  << (result ? "✅ true" : "❌ false") << std::endl;
    }

    std::cout << "\nВведите свою последовательность (или 'q' для выхода):" << std::endl;
    std::string input;
    while (std::getline(std::cin, input) && input != "q") {
        if (input.empty()) continue;
        bool result = isValidBrackets(input);
        std::cout << (result ? "✅ Корректная последовательность" : "❌ Некорректная последовательность") << std::endl;
        std::cout << "Введите следующую последовательность (или 'q' для выхода):" << std::endl;
    }

    return 0;
}