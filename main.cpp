﻿// OS_Lab2.cpp: определяет точку входа для приложения.
//

#include<iostream>
#include<vector>
#include<windows.h>

using namespace std;

struct ThreadData
{
	vector<int>arr;
	int minVal, maxVal;
	double average;

	ThreadData(int size) : arr(size), minVal(-1), maxVal(-1), average(0.0) {};
};

DWORD WINAPI min_max(LPVOID lpParameter)
{
	ThreadData* data = static_cast<ThreadData*>(lpParameter);
	data->minVal = data->arr[0];
	data->maxVal = data->arr[0];

	for (int i = 0; i < data->arr.size(); i++)
	{
		if (data->arr[i] < data->minVal)	data->minVal = data->arr[i];
		else								data->maxVal = data->arr[i];

		Sleep(7);
	}
	cout << "Min array element: \t" << data->minVal << "\nMax array element:\t" << data->maxVal << endl;
	return 0;
}

DWORD WINAPI average(LPVOID lpParameter)
{
	ThreadData* data = static_cast<ThreadData*>(lpParameter);

	for (int i = 0; i < data->arr.size(); i++)
	{
		data->average += data->arr[i];
		Sleep(12);
	}
	cout << "Average value of array elements:\t" << data->average << endl;
	return 0;
}

int main()
{
	int n;
	cout << "Enter the size of array:\t";
	cin >> n;
	ThreadData* data = new ThreadData(n);
	cout << "Enter " << n << " elements:\t";
	for (int i = 0; i < n; i++)
	{
		cin >> data->arr[i];
		cout << "\t";
	}
	cout << endl;
	
	HANDLE hMinMax, hAverage;
	DWORD IDMinMax, IDAverage;

	hMinMax = CreateThread(NULL, 0, min_max, data, 0, &IDMinMax);
	if (hMinMax == nullptr)
	{
		cout << "Error generating thread MinMax\n";
		return GetLastError();
	}
	else
	{
		cout << "\n/// Thread MinMax created ///\n\n";
	}
	WaitForSingleObject(hMinMax, INFINITE);
	CloseHandle(hMinMax);

	hAverage = CreateThread(NULL, 0, average, data, 0, &IDAverage);
	if (hAverage == nullptr)
	{
		cout << "Error generating thread Avreage\n";
		return GetLastError();
	}
	else
	{
		cout << "\n/// Thread Average created ///\n\n";
	}

	WaitForSingleObject(hAverage, INFINITE);
	CloseHandle(hAverage);	
	

	return 0;
}
