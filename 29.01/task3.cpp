#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matrix[N][N];
    
    // Ввод элементов матрицы
    cout << "Введите элементы матрицы 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Вычисление сумм
    int mainDiagSum = 0, secondaryDiagSum = 0, totalSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            totalSum += matrix[i][j];
            if (i == j) mainDiagSum += matrix[i][j];          // Главная диагональ
            if (i + j == N - 1) secondaryDiagSum += matrix[i][j]; // Побочная диагональ
        }
    }
    
    // Проверка симметричности относительно главной диагонали
    bool isSymmetric = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    
    // Вывод результатов
    cout << "\nСумма элементов главной диагонали: " << mainDiagSum << endl;
    cout << "Сумма элементов побочной диагонали: " << secondaryDiagSum << endl;
    cout << "Сумма всех элементов матрицы: " << totalSum << endl;
    cout << "Матрица " << (isSymmetric ? "является" : "НЕ является") 
         << " симметричной относительно главной диагонали" << endl;
    
    return 0;
}