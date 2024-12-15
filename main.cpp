// OS_Lab2.cpp: определяет точку входа для приложения.
//

#include<iostream>
#include<vector>
#include<windows.h>
#include<ThreadData.h>
#include<threads.h>

using namespace std;

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
		cout << "Error generating MinMax thread\n";
		return GetLastError();
	}
	else
	{
		cout << "\n/// Thread MinMax created ///\n\n";
	}
	WaitForSingleObject(hMinMax, INFINITE);

	if (CloseHandle(hMinMax))
	{
		cout << "\n///Thread MinMax completed///\n\n";
	}

	hAverage = CreateThread(NULL, 0, average, data, 0, &IDAverage);
	if (hAverage == nullptr)
	{
		cout << "Error generating Average thread\n";
		return GetLastError();
	}
	else
	{
		cout << "\n/// Thread Average created ///\n\n";
	}

	WaitForSingleObject(hAverage, INFINITE);
	if (CloseHandle(hAverage))
	{
		cout << "\n/// Thread Average completed ///\n\n";
	}
	cout << "Final array output:"<<endl<<"[ ";
	for (int i = 0; i < data->arr.size(); i++)
	{
		if (data->arr[i] == data->minVal || data->arr[i] == data->maxVal)
		{
			data->arr[i] = data->average;
		}
		cout << data->arr[i] << " ";
	}
	cout << "]"<<endl;
	return 0;
}
