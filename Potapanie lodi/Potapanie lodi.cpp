#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

ifstream uvod;
ofstream pokusy;
int maxlode = 5;
int pole[5][5] = 
{
	{1,2,3,4,5,},
	{1,2,3,4,5,},
	{1,2,3,4,5,},
	{1,2,3,4,5,},
	{1,2,3,4,5,}
};

void lode() 
{
	int l = 0;
	while (l < maxlode)
	{
		int x = rand() % 5;
		int y = rand() % 5;
		if (pole[x][y] != 1)
		{
			l++;
			pole[x][y] = 1;
		}
	}
}

int pocetLodi()
{
	int m = 0;
	for (int j = 0; j < 5; j++) 
	{
		for (int k = 0; k < 5; k++) 
		{
			if (pole[j][k] == 1)
				m++;
		}
	}
	return m;
}

bool utok(int x, int y)
{
	if (pole[x][y] == 1)
	{
		pole[x][y] = 2;
		return true;
	}
	return false;
}

int main() {
	int b = 0;
	char start;
	int pozicia, pozicia2;

	uvod.open("uvod.txt");
	cout << uvod.rdbuf();
	uvod.close();

	cout << endl;
	cin >> start;
	switch (start)
	{
	case '1':
		Pokracovanie:
		srand(time(NULL));

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				pole[j][k] = 0;
			}
		}
		lode();

		utok(1, 1);

		system("CLS");
		do
		{
			opakovanie:
			cout << "Zadaj poziciu: ";
			cin >> pozicia >> pozicia2;
			if (pozicia >= 6 || pozicia <= 0) {
				system("CLS");
				cout << "Zadal si zlu poziciu(1-5)\n";
				goto opakovanie;
			}
			if (pozicia2 >= 6 || pozicia2 <= 0) {
				system("CLS");
				cout << "Zadal si zlu poziciu(1-5)\n";
				goto opakovanie;
			}
			pozicia = pozicia - 1;
			pozicia2 = pozicia2 - 1;
				if (utok(pozicia, pozicia2))
				{
					system("CLS");
					cout << "Trafil si sa" << endl;
					cout << "Pocet lodi je: " << pocetLodi() << endl;
					cout << "----------------" << endl;

				}

				else 
				{
					system("CLS");
					cout << "Netrafil si sa" << endl;
					cout << "Pocet lodi je: " << pocetLodi() << endl;
					cout << "----------------" << endl; 
				}	 
				b = b + 1;

		} 
		while (pocetLodi() > 0);
		{
			pokusy.open("pokusy.txt");
			pokusy << "Tvoj pocet pokusov:" << endl;
			pokusy << b;
			pokusy.close();

			system("CLS");
			cout << "Gratulujem vyhral si!\n";
			Rozhodnutie:
			cout << "Chces pokracovat?\n";
			cout << "1.Ano\n" << "2.Nie\n";
			char opakovanie;
			cin >> opakovanie;
			switch (opakovanie)
			{
			case '1':
				system("CLS");
				goto Pokracovanie;
				break;
			case '2':
				return 0;
				break;
			default:
				system("CLS");
				cout << "----------------------\n";
				cout << "Zadal si zlu moznost!\n";
				cout << "----------------------\n";
				goto Rozhodnutie;
				break;
			}
		}
		break;
	case '2':
		return 0;
		break;
	}
}