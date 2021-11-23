#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Functions.h" // ��������������� �������

using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	system("color 3");

	int size; // ������ �������

	cout << "=================================" << endl;
	cout << "������� ������ �������: ";
	cin >> size;
	cout << "=================================" << endl << endl;

	int* arr = new int[size];
	int* buff = new int[size];

	int d1, d2;
	int step;

	cout << "������� �������� � ��� ��� ��������� �������� �������" << endl;
	cout << "=================================" << endl;
	cout << "��������: ";
	cin >> d1 >> d2;
	cout << endl;

	cout << "��� ��� ���������: ";
	cin >> step;
	cout << "=================================" << endl << endl;

	cout << "=================================" << endl;
	cout << "1 - ��������� ������ ���������� ������� (������, �������������� � ��������������)" << endl;
	cout << "2 - ��������� ������ �������" << endl;
	cout << "3 - ��������� ������ ���������� �������������� �������" << endl;
	cout << "4 - ��������� ������ ���������� ���������� �������" << endl;
	cout << "=================================" << endl;

	int choice;
	cout << "��� �����: ";
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

	bool tmp; // ��� ������ ������ ����������

	cout << "�������� ����� ���������� �������" << endl;
	cout << "=================================" << endl;
	cout << "0 - ���������� ��������" << endl;
	cout << "1 - ����������� ����������" << endl;
	cout << "=================================" << endl;

	cin >> tmp;

	for (size = d1; size <= d2; size += step) {
		selectSort(size, tmp);
	}

	cout << "=================================" << endl;
	cout << "���������� ������ ��������� ��������� � ����� file.txt" << endl;
	cout << "=================================" << endl;

	return 0;
}
