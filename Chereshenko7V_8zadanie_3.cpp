// В текстовом файле input.txt записан русский текст.
// Найти в тексте слова, содержащие не менее четырех различных гласных букв,
//  записать их заглавными буквами
//  и указать после каждого такого слова в скобках найденные буквы.
// Полученный текст записать в файл output.txt.
// Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания

#include <iostream>
#include <fstream>

int main()
{
	setlocale(LC_ALL, "Rus");
	std::string word;
	int number_of_words = 0;
	std::string vowels = "ёуеыаоэяию";

	std::ifstream in;
	in.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\input.txt");
	if (!in.is_open())
	{
		std::cout << "Input file isn't open! ";
		return -1;
	}

	std::ofstream out;
	out.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\output.txt");
	if (!in.is_open())
	{
		std::cout << "Output file isn't open! ";
		return -2;
	}
	for (int index = 1; in >> word; index++)
	{
		int count = 0;
		std::string finded_vowels = "(";
		for (int i = 0; i < vowels.length(); i++)
			for (int j = 0; j < word.length(); j++)
			{
				if (vowels[i] == word[j])
				{
					count++;
					finded_vowels += vowels[i];
					break;
				}
			}
		std::string punct;
		int lastpos;
		if (count >= 4)
		{
			for (int i = 0; i < word.length(); i++)
			{
				word[i] = toupper(word[i]);
			}
			lastpos = word.length() - 1;
			for (int i = lastpos; i >= 0; i--)
			{
				if (ispunct(word[i]) || isdigit(word[i]))
				{
					punct+=word[i];
					word.erase(i,1);
				}
				else
				{
					word += finded_vowels + ")" + punct;
					break;
				}
			}
		}
		std::cout << word << " ";
		out << word << " ";
		if (index % 13 == 0)
		{
			out << std::endl;
			std::cout << std::endl;
		}
	}
	in.close();
	out.close();
	return 0;
}