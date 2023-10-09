#include <iostream>
int main()
{
	unsigned int N;
	bool flag = false;
	unsigned long long proiz = 1;
	std::cin >> N;
	while (N)
	{
		if ((N % 10) % 2 == 0)
		{
			proiz *= N % 10;
			flag = true;
		}
		N /= 10;
	}
	if (flag)
	{
		std::cout << proiz;
	}
	else
	{
		std::cout << "0";
	}
	return 0;
}