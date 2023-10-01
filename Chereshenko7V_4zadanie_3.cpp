#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	short x;
	std::cout << "Input (-1) or (1)"<< std::endl;
	std::cin >> x;
	if (x == -1) {
		std::cout << "Negative number";
	}
	else if (x==1) {
		std::cout << "Positive number";
	}
	return 0;
}
