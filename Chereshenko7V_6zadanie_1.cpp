#include <iostream>
using namespace std;

int main()
{
	const int dlina = 1000; // lenght of massive
	int array[dlina];
	int i;
	short elem;
	int suma = 0;
	int minimum = 100000;
	for (i = 0; i < dlina; i++) // massive generation
	{
		array[i] = i + 1;
	}
	for (i = 0; i < dlina; i++)
	{
		if ((array[i] % 3 == 0) || (array[i] % 7 == 0))
		{
			suma += int(array[i]);

			if (minimum > array[i])
			{
				minimum = array[i];
				elem = i;
			}
		}
	}
	cout << "Summa = " << suma << endl;
	cout << "Minimum array[" << elem << "] = " << minimum;
	return 0;
}