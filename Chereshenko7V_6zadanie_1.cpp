#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[150];
	int i;
	int dlina = 20; // Âûáèðàåì äëèíó ìàññèâà
	int suma = 0;
	int minimum = 1000;
	for (i = 0; i < dlina; i++) // Áëîê ãåíåðàöèè ìàññèâà (â äàííîì íàïèñàíèè êîäà ìîæíî ìåíÿòü ñïîñîáû ãåíåðàöèè ìàññèâà)
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
			}
		}
	}
	cout << "Ñóììà òàêèõ ÷èñåë ðàâíà: " << suma << endl;
	cout << "Ìèíèìàëüíîå èç òàêèõ ÷èñåë ðàâíî: " << minimum;
	return 0;
}
