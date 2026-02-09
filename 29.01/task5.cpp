#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    int grades[5];
    double averageGrade;

public:
    // Конструктор
    Student(const string& studentName, const int marks[5]) {
        name = studentName;
        for (int i = 0; i < 5; i++) {
            grades[i] = marks[i];
        }
        calculateAverage();
    }
    
    // Вычисление среднего балла
    void calculateAverage() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i];
        }
        averageGrade = static_cast<double>(sum) / 5;
    }
    
    // Вывод информации о студенте
    void printInfo() const {
        cout << "Студент: " << name << endl;
        cout << "Оценки: ";
        for (int i = 0; i < 5; i++) {
            cout << grades[i];
            if (i < 4) cout << ", ";
        }
        cout << endl;
        cout << fixed << setprecision(1);
        cout << "Средний балл: " << averageGrade << endl;
    }
    
    // Проверка на отличника (все оценки >= 8)
    bool hasExcellentGrades() const {
        for (int i = 0; i < 5; i++) {
            if (grades[i] < 8) return false;
        }
        return true;
    }
    
    // Изменение оценки с проверкой индекса
    bool changeGrade(int subjectIndex, int newGrade) {
        if (subjectIndex < 0 || subjectIndex >= 5 || newGrade < 1 || newGrade > 10) {
            return false;
        }
        grades[subjectIndex] = newGrade;
        calculateAverage(); // Пересчитываем средний балл
        return true;
    }
    
    // Геттер для среднего балла (для поиска лучшего студента)
    double getAverageGrade() const {
        return averageGrade;
    }
    
    // Геттер для имени
    string getName() const {
        return name;
    }
};

int main() {
    // Создание объектов студентов
    int marks1[5] = {8, 9, 7, 10, 9};
    int marks2[5] = {6, 5, 7, 8, 7};
    int marks3[5] = {10, 10, 9, 10, 10};
    
    Student s1("Иванов И.И.", marks1);
    Student s2("Петров П.П.", marks2);
    Student s3("Сидорова А.В.", marks3);
    
    // Тестирование методов для первого студента
    cout << "=== Информация о студенте 1 ===" << endl;
    s1.printInfo();
    cout << "Отличник: " << (s1.hasExcellentGrades() ? "да" : "нет") << endl;
    
    // Изменение оценки
    if (s1.changeGrade(2, 9)) {
        cout << "\nПосле изменения оценки по предмету 3:" << endl;
        s1.printInfo();
    }
    
    // Массив студентов и поиск лучшего
    Student* students[] = {&s1, &s2, &s3};
    int count = 3;
    Student* bestStudent = students[0];
    
    for (int i = 1; i < count; i++) {
        if (students[i]->getAverageGrade() > bestStudent->getAverageGrade()) {
            bestStudent = students[i];
        }
    }
    
    cout << "\n=== Студент с наивысшим средним баллом ===" << endl;
    bestStudent->printInfo();
    
    return 0;
}