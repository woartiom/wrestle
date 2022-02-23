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

void RandArray(int arr[], int size, int from, int to)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (to - from) + from;
	}
}

void CoutArray(int arr[], int size)
{
	cout << endl << "| ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " | ";
	}
	cout << endl << endl;
}

void RandBoxes(int arr[], int size)
{
	int x, i, j;

	for (i = 0; i < size; i++)
	{
		x = arr[i];
		for (j = i - 1; j >= 0 && arr[j] != x && arr[j] != arr[i]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = x;
	}
}


void All(int arr[], int size)
{
	int left = -1;
	int right = -1;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			right = i;
		}
	}
	
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			left = i;
		}
	}

	for (int n = 0; n < size; n++)
	{
		for (int i = left; i < right; i++)
		{
			int k = i;
			int x = arr[i];
			for (int j = i + 1; j < right; j++)
			{
				if (arr[j] < x)
				{
					k = j;
					x = arr[j];
				}
				arr[k] = arr[i];
				arr[i] = x;
			}
		}
	}

	CoutArray(arr, size);
}

void SortArray1(int arr[], int size, int cînst)
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

	else { cout << "error" << endl; }
}

void SortArray2(int arr[], int size, int key)
{
	int x, i, j;
	for (i = 0; i < key; i++)
	{
		x = arr[i];
		for (j = i - 1; j >= 0 && arr[j] < x; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
	for (i = key + 1; i < size; i++)
	{
		x = arr[i];
		for (j = i - 1; j >= key + 1 && arr[j] > x; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}

	CoutArray(arr, size);
}

int SearchRandedElem(int arr[], int size, int number)
{
	for (int i = 0; i < size; i++)
	{
		if (number == arr[i])
		{
			return i;
		}
	}
	return 11;
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
			// Creating an array
			const int size = 10;
			int arr[size], answer, cînst = 1;

			// Calling functions
			RandArray(arr, size, 0, 100);
			CoutArray(arr, size);

			cout << "Descending -> 1" << endl;
			cout << "Ascending  -> 0" << endl;
			cout << "choose one: ";
			cin >> answer;

			if (answer != 0)
			{
				SortArray1(arr, size, cînst);
			}
			else
			{
				SortArray1(arr, size, answer);
			}

			cout << endl << "Result (down)";
			CoutArray(arr, size);
		}break;
		case 2:
		{
			srand(time(NULL));
			
			const int size = 10;
			int arr[size], right_min_elem{}, right_num_box;

			RandArray(arr, size, -20, 20);
			CoutArray(arr, size);

			All(arr, size);

		}break;
		case 3:
		{
			const int size = 20;
			int arr[size];
			int number, check;

			// STEP 0 (reate randed array (numbers))
			RandArray(arr, size, 1, 20);
			CoutArray(arr, size);

			_getch();
			system("cls");

			// STEP 1 (rand boxes)
			RandBoxes(arr, size);
			CoutArray(arr, size);

			_getch();
			system("cls");

			// STEP 2 (rand number)
			for (int i = 0; i < 3; i++)
			{
				srand(time(NULL));
				number = rand() % 19 + 1;
			}

			// STEP 2.1 (check randed element in array)
			check = SearchRandedElem(arr, size, number);

			if (check != 11)
			{
				cout << "Number " << number;
				cout << " is in array as numbered [";
				cout << check << "] (old version array)" << endl;

				SortArray2(arr, size, check);
			}

			else { cout << "error"; }
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