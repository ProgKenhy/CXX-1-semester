#include <iostream>
int main()
{
    setlocale(LC_ALL, "Rus");
    int N;
    std::cin >> N;
    std::string day;
    switch (N) {
    case 1:
        day = "�����������";
        break;
    case 2:
        day = "�������";
        break;
    case 3:
        day = "�����";
        break;
    case 4:
        day = "�������";
        break;
    case 5:
        day = "�������";
        break;
    case 6:
        day = "�������";
        break;
    case 7:
        day = "�����������";
        break;
    default:
        day = "�� ����������";
    }
    std::cout << "���� ������: " << day;
    return 0;
}