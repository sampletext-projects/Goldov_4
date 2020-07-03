#include <iostream>
#include <fstream>

using namespace std;

int col_max_sum(int matr[3][3])
{
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		int max = matr[0][i];
		for (int j = 0; j < 3; j++)
		{
			if (matr[j][i] > max)
			{
				max = matr[j][i];
			}
		}
		sum += max;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "russian");

	int matr[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> matr[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << "\n";
	}

	int sum = col_max_sum(matr);

	int k;

	cout << "Новый файл (1), существующий файл(любое число)?: ";
	cin >> k;
	ofstream f;
	if (k == 1)
	{
		cin.ignore();
		char file[50];
		cout << "Введите название файла: ";
		cin.getline(file, 50);

		f.open(file);
	}
	else
	{
		f.open("out.txt");
	}

	f << sum;

	f.close();

	cout << "Результат записан\n";

	system("pause");
}
