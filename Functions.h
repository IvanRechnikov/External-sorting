#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "MergeSort.h"
#include "MergeSort3Way.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;


void RandIcreaseArray(int arr[], int size) { // ��������� ���������� �������������� �������
	int a, b;
	for (int i = 0; i < size; i++) {
		a = rand() % 101 - 50;
		b = rand() % 101 - 50;

		if (a < b)
			arr[i] = a;
		else
			arr[i] = b;
	}
}

void RandWaningArray(int arr[], int size) { // ��������� ���������� ���������� �������
	int a, b;
	for (int i = 0; i < size; i++) {
		a = rand() % 101 - 50;
		b = rand() % 101 - 50;

		if (a > b)
			arr[i] = a;
		else
			arr[i] = b;
	}
}

void wholewithnegative(int arr[], int size) { // ��������� ��������� ����� 
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 101 - 50;
}

void display(int arr[], int size) { // ��� ������ �������
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void in(int arr[], int size) { // ��� ����� ������ �������
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void selectSort(int size, bool tmp) {
	clock_t start, end, search;

	ofstream out;
	out.open("file.txt", ios::app);

	int* arr = new int[size];
	int* buff = new int[size];
	wholewithnegative(arr, size);


		
	if (!tmp) {
		start = clock();
		merge_sort(arr, buff, 0, size);
		end = clock();
		search = end - start;
		
		
		out << "=================================" << endl;
		out << "���������� ��������� - " << size << endl;
		out << "����� ������ - " << search << " ���" << endl;
		out << "=================================" << endl;
	}
	else {
		start = clock();
		mergeSort3Way(arr, size);
		end = clock(); 
		search = end - start; 

		out << "=================================" << endl;
		out << "���������� ��������� - " << size << endl;
		out << "����� ������ - " << search << " ���" << endl;
		out << "=================================" << endl;
	}
}

#endif
