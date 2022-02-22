#include <iostream>
#include <conio.h>
using namespace std;

void Menu()
{
	cout << "#>-------<EXERCISES>-------<#" << endl;
	cout << "|Topic: Git                 |" << endl;
	cout << "|         1 >---< 1         |" << endl;
	cout << "|         2 >---< 2         |" << endl;
	cout << "|         3 >---< 3         |" << endl;
	cout << "|                      /---<#" << endl;
	cout << "#>----------------Input -> ";
}

void Func1(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Func2(int arr[], int size)
{
	cout << endl << "| ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " | ";
	}
	cout << endl << endl;
}

void Sort(int arr[], int size, int cînst = 1)
{
	if (cînst == 0)
	{
		for (int i = 0; i < size; i++)
		{
			int swap1 = arr[i], swap2;
			for (swap2 = i - 1; swap2 >= 0 && arr[swap2] > swap1; swap2--)
			{
				arr[swap2 + 1] = arr[swap2];
			}
			arr[swap2 + 1] = swap1;
		}
	}
	else if (cînst == 1)
	{
		for (int i = 0; i < size; i++)
		{
			int swap1 = arr[i], swap2;
			for (swap2 = i - 1; swap2 >= 0 && arr[swap2] < swap1; --swap2)
			{
				arr[swap2 + 1] = arr[swap2];
			}
			arr[swap2 + 1] = swap1;
		}
	}
	else
	{
		cout << endl << "error" << endl;
	}
}


int main()
{
	while (true)
	{
		int answer;
		Menu();
		cin >> answer;

		srand(time(NULL));
		switch (answer)
		{
		case 0: { return 0; }
		case 1:
		{
			// Create an array
			const int size = 10;
			int arr[size], answer, cînst = 1;

			// Call functions
			Func1(arr, size);
			Func2(arr, size);

			cout << "Descending -> 1" << endl;
			cout << "Ascending  -> 0" << endl;
			cout << "choose one: ";
			cin >> answer;

			if (answer != 0)
			{
				Sort(arr, size, cînst);
			}
			else
			{
				Sort(arr, size, answer);
			}

			cout << endl << "Result (down)";
			Func2(arr, size);
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

		_getch();
		system("cls");
	}
	return 0;
}