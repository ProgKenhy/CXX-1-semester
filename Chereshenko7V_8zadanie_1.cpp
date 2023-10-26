// Äàí ôàéë, ñîäåðæàùèé ðóññêèé òåêñò.
//  Íàéòè â òåêñòå N<=2000 ñàìûõ äëèííûõ ñëîâ, íå ñîäåðæàùèõ îäèíàêîâûõ ñîãëàñíûõ.
//  Çàïèñàòü íàéäåííûå ñëîâà â òåêñòîâûé ôàéë â ïîðÿäêå íåâîçðàñòàíèÿ äëèíû.
//  Âñå íàéäåííûå ñëîâà äîëæíû áûòü ðàçíûìè!
#include <iostream>
#include <fstream>

char tolower(char x)
{
	if ('À' <= x && x <= 'ß')
		return x += 32;
	return x;
}
int wordlength(char *x)
{
	int len = 0;
	while (x[len] != '\0')
	{
		len++;
	}
	return len;
}

bool issoglasnyedifferent(char *x, char *y)
{
	for (int i = 0; i < wordlength(x); i++)
	{
		int count = 0;
		for (int j = 0; j < wordlength(y); j++)
		{
			if (x[i] == y[j])
			{
				count++;
				if (count > 1)
					return false;
			}
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 2001;
	char word[100] = {0};
	char result[n][100] = {0};
	char soglasnye[43] = "áâãäæçéêëìíïðñòôõö÷øù"; 
	std::ifstream infile;
	infile.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\input.txt");
	if (!infile.is_open())
	{
		std::cout << "Input file dod not find!";
		return -1;
	}
	int lastpos = 0;
	std::cout << "Input value of numbers: ";
	int k, inminlen = 0;
	std::cin >> k;
	while (!infile.eof())
	{
		infile >> word;
		word[0] = tolower(word[0]);
		lastpos = wordlength(word) - 1;
		for (int i = lastpos; i >= 0; i--)
		{
			if (ispunct(word[i]) || (isdigit(word[i])))
				word[i] = '\0';
			else
				break;
		}
		if ((wordlength(word)) > wordlength(result[inminlen]))
		{
			int maxlen = 0;
			bool flag;
			if (issoglasnyedifferent(soglasnye, word))
			{
				for (int q = 0; q < k; q++)
				{
					flag = false;
					int countofequvalent = 0;
					if (wordlength(result[q]) < wordlength(word))
						maxlen = wordlength(word);
					else
						maxlen = wordlength(result[q]);
					for (int w = 0; w < maxlen; w++)
					{
						if (word[w] != result[q][w])
						{
							flag = true;
						}
					}
					if (!flag)
						break;
				}
				if (flag)
				{
					for (int b = 0; b < wordlength(word); b++)
					{
						result[inminlen][b] = word[b];
					}
					for (int c = 0; c < k; c++)
						if (wordlength(result[inminlen]) > wordlength(result[c]))
						{
							inminlen = c;
						}
				}
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
		{
			if (wordlength(result[i]) < wordlength(result[j]))
			{
				for (int b = 0; b < 100; b++)
				{
					char tmp;
					tmp = result[i][b];
					result[i][b] = result[j][b];
					result[j][b] = tmp;
				}
			}
		}
	std::ofstream outfile;
	outfile.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\output.txt");
	for (int i = 0; i < k; i++)
	{
		std::cout << "TOP " << i + 1 << ": " << result[i] << std::endl;
	}
	for (int i = 0; i < k; i++)
	{
		if (infile.is_open())
		{
			outfile << "TOP " << i + 1 << ": " << result[i] << std::endl;
		}
		else
		{
			std::cout << "Output file did not find!";
			return -2;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}
