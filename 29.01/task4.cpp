#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Подсчет гласных букв (с учетом русского алфавита)
int countVowels(const string& str) {
    string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    int count = 0;
    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Удаление пробелов из строки
void removeSpaces(string& str) {
    string result;
    for (char c : str) {
        if (c != ' ') result += c;
    }
    str = result;
}

// Проверка палиндрома (без учета регистра и пробелов)
bool isPalindrome(const string& str) {
    string cleaned;
    for (char c : str) {
        if (c != ' ') {
            cleaned += tolower(static_cast<unsigned char>(c));
        }
    }
    
    int left = 0, right = cleaned.length() - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string testStr = "А роза упала на лапу Азора";
    
    // Тестирование функций
    cout << "Исходная строка: \"" << testStr << "\"" << endl;
    
    int vowels = countVowels(testStr);
    cout << "Количество гласных: " << vowels << endl;
    
    string noSpaces = testStr;
    removeSpaces(noSpaces);
    cout << "Без пробелов: \"" << noSpaces << "\"" << endl;
    
    bool palindrome = isPalindrome(testStr);
    cout << "Палиндром: " << (palindrome ? "да" : "нет") << endl;
    
    return 0;
}