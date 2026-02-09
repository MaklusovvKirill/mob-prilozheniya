#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    
    // Инициализация генератора случайных чисел
    srand(time(0));
    
    // Заполнение массива случайными числами от 1 до 100
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    // Вывод исходного массива
    cout << "Массив: [";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
        if (i < SIZE - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Поиск максимума, минимума и суммы
    int maxVal = arr[0], minVal = arr[0], sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
        sum += arr[i];
    }
    
    // Расчет среднего арифметического
    double average = static_cast<double>(sum) / SIZE;
    
    // Вывод результатов
    cout << "Максимальный элемент: " << maxVal << endl;
    cout << "Минимальный элемент: " << minVal << endl;
    cout << fixed << setprecision(1);
    cout << "Среднее арифметическое: " << average << endl;
    
    return 0;
}