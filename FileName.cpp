#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count);
int rowCharacteristic(int* row, int cols);
void sortRowsByCharacteristic(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -20;
	int High = 20;

	int rowCount, colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	//Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int count = 0;

	if (Part1_Count(a, rowCount, colCount, count))
		cout << "count = " << count << endl;
	else
		cout << "there are no zero elements" << endl;
	cout << endl;

	sortRowsByCharacteristic(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count)
{
	bool result = false;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
			if (a[i][j] == 0)
			{
				result = true;
				count++;
				break;
			}
	}
	return result;
}

// Функція для обчислення суми додатних парних елементів у рядку
int rowCharacteristic(int* row, int cols) {
	int sum = 0;
	for (int i = 0; i < cols; ++i) {
		if (row[i] > 0 && row[i] % 2 == 0) {
			sum += row[i];
		}
	}
	return sum;
}

void sortRowsByCharacteristic(int** a, const int rowCount, const int colCount) {
	// Сортування матриці за характеристиками рядків (методом бульбашки)
	for (int i = 0; i < rowCount - 1; ++i) {
		for (int j = 0; j < rowCount - i - 1; ++j) {
			if (rowCharacteristic(a[j], colCount) > rowCharacteristic(a[j + 1], colCount)) {
				for (int k = 0; k < colCount; ++k) {
					int temp = a[j][k];
					a[j][k] = a[j + 1][k];
					a[j + 1][k] = temp;
				}
			}
		}
	}
}
