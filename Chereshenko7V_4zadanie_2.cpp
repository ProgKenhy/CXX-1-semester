#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");
    int N;
    std::cin >> N;
    std::string day;
    switch (N) {
    case 1:
        day = "Понедельник";
        break;
    case 2:
        day = "Вторник";
        break;
    case 3:
        day = "Среда";
        break;
    case 4:
        day = "Четверг";
        break;
    case 5:
        day = "Пятница";
        break;
    case 6:
        day = "Суббота";
        break;
    case 7:
        day = "Воскресенье";
        break;
    default:
        day = "не существует";
    }
    std::cout << "День недели: " << day;
    return 0;
}