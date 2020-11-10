#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
void min_max(int* mas, int min, int max, int i, int N)
{
	if (i <= N - 1)
	{
		if (mas[i] < min)
			min = mas[i];
		if (mas[i] > max)
			max = mas[i];
		return min_max(mas, min, max, ++i, N);
	}
	cout << endl;
	cout << "—ума максимального та м≥н≥мального числа масиву : " << min + max << endl;
}
void rec(int* mas, const int Low, const int Max, int N, int i)
{
	if (i <= N - 1)
	{
		mas[i] = Low + rand() % (Max - Low + 1);
		cout << setw(3) << mas[i] << " ";
		return rec(mas, Low, Max, N, ++i);
	}
	else min_max(mas, mas[0], mas[0], 0, N);
}
int main()
{
	int N, Low, Max;
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "¬вед≥ть к≥льк≥сть елемент≥в масиву: "; cin >> N;
	cout << "¬вед≥ть м≥н≥мальне значенн€ масиву: "; cin >> Low;
	cout << "¬вед≥ть максимальне значенн€ масиву: "; cin >> Max;
	cout << endl;
	int* mas = new int[N];
	cout << "–екурсивний" << endl;
	rec(mas, Low, Max, N, 0);
}
