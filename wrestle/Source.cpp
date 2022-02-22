#include <iostream>
#include <conio.h>
using namespace std;

void Menu()
{
	cout << "#>-------<EXERCISES>-------<# << endl";
	cout << "|Topic: Git                 | << endl";
	cout << "|         1 >---< 1         | << endl";
	cout << "|         2 >---< 2         | << endl";
	cout << "|         3 >---< 3         | << endl";
	cout << "|                      /---<# << endl";
	cout << "#>----------------Input -> ";
}

int main()
{

	while (true)
	{
		int answer;
		Menu();
		cin >> answer;

		switch (answer)
		{
		case 0: { return 0; }
		case 1:
		{

		}break;
		case 2:
		{

		}break;
		case 3:
		{

		}break;
		default:
			cout << "error";
			break;
		}
		_getch;
		system("cls");
	}
	return 0;
}