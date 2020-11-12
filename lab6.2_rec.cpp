#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(int* mas, const int Low, const int Max, int N, int i);
void print(int* mas, int i, int N);
int MinE(int* mas, int N, int i, int min);
int MaxE(int* mas, int N, int i, int max);

int main()
{
	int N, Low, Max;
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введіть кількість елементів масиву: "; cin >> N;
	cout << "Введіть мінімальне значення масиву: "; cin >> Low;
	cout << "Введіть максимальне значення масиву: "; cin >> Max;
	cout << endl;
	int* mas = new int[N];
	cout << "Рекурсивний" << endl;
	create(mas, Low, Max, N, 0);
	print(mas, 0, N);
	cout << endl;
	int min = MinE(mas, N, 0, mas[0]);
	int max = MaxE(mas, N, 0, mas[0]);
	cout << "Мінімальне: " << min << endl;
	cout << "Максимальне: " << max << endl;
	cout << "Сума максимального та мінімального: " << min + max << endl;
	delete[] mas;
}
void create(int* mas, const int Low, const int Max, int N, int i)
{
	if (i <= N - 1)
	{
		mas[i] = Low + rand() % (Max - Low + 1);
		create(mas, Low, Max, N, ++i);
	}
}
void print(int* mas, int i, int N)
{
	if (i <= N - 1)
	{
		cout << setw(3) << mas[i] << " ";
		print(mas, ++i, N);
	}

}
int MinE(int* mas, int N, int i, int min)
{
	if (i <= N - 1)
	{
		if (mas[i] < min)
			min = mas[i];
		MinE(mas, N, ++i, min);
	}
	else
	return min;
}
int MaxE(int* mas, int N, int i, int max)
{
	if (i <= N - 1)
	{
		if (mas[i] > max)
			max = mas[i];
		MaxE(mas, N, ++i, max);
	}
	else
	return max;
}
