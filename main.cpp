#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Functions.h" // Вспомогательные функции

using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	system("color 3");

	int size; // размер массива

	cout << "=================================" << endl;
	cout << "Введите размер массива: ";
	cin >> size;
	cout << "=================================" << endl << endl;

	int* arr = new int[size];
	int* buff = new int[size];

	int d1, d2;
	int step;

	cout << "Введите диапазон и шаг для изменения размеров массива" << endl;
	cout << "=================================" << endl;
	cout << "Диапазон: ";
	cin >> d1 >> d2;
	cout << endl;

	cout << "Шаг для изменения: ";
	cin >> step;
	cout << "=================================" << endl << endl;

	cout << "=================================" << endl;
	cout << "1 - заполнить массив случайными числами (целыми, положительными и отрицательными)" << endl;
	cout << "2 - заполнить массив вручную" << endl;
	cout << "3 - заполнить массив случайными упорядоченными числами" << endl;
	cout << "4 - заполнить массив случайными убывающими числами" << endl;
	cout << "=================================" << endl;

	int choice;
	cout << "Ваш выбор: ";
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		wholewithnegative(arr, size);
		//display(arr, size);
	}
	else if (choice == 2) {
		in(arr, size);
		//display(arr, size);
	}
	else if (choice == 3) {
		RandIcreaseArray(arr, size);
		//display(arr, size);
	}
	else if (choice == 4) {
		RandWaningArray(arr, size);
		//display(arr, size);
	}

	bool tmp; // для выбора метода сортировки

	cout << "Выберите метод сортировки массива" << endl;
	cout << "=================================" << endl;
	cout << "0 - Сортировка слиянием" << endl;
	cout << "1 - Многофазная сортировка" << endl;
	cout << "=================================" << endl;

	cin >> tmp;

	for (size = d1; size <= d2; size += step) {
		selectSort(size, tmp);
	}

	cout << "=================================" << endl;
	cout << "Результаты работы программы находятся в файле file.txt" << endl;
	cout << "=================================" << endl;

	return 0;
}
