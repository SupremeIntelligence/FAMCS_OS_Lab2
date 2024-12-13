// OS_Lab2.cpp: определяет точку входа для приложения.
//

#include "OS_Lab2.h"
#include<iostream>
#include<windows.h>

using namespace std;

DWORD WINAPI min_max()
{
	return 0;
}

DWORD WINAPI average()
{
	return 0;
}

int main()
{
	int n;
	cout << "Enter the size of array:\t";
	cin >> n;
	int* arr = new int [n];
	cout << "Enter " << n << " elements:\t";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cout << "\t";
	}
	cout << endl;

	HANDLE hThread;
	DWORD IDThread;

	hThread = CreateThread(NULL, 0, nullptr, nullptr, 0, &IDThread);
	if (hThread == nullptr)
	{
		return GetLastError();
	}
	return 0;
}
