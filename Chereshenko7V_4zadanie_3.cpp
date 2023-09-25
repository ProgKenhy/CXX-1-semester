#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	short x;
	std::cout << "¬ведите значение (-1) или (1)"<< std::endl;
	std::cin >> x;
	if (x == -1) {
		std::cout << "Negative number";
	}
	else if (x==1) {
		std::cout << "Positive number";
	}
	return 0;
}