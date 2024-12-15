// OS_Lab2.cpp: определяет точку входа для приложения.
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

	ThreadData(int size) : minVal(-1), maxVal(-1), average(0.0) 
	{
		if (size <= 0)
		{
			arr.resize(0);
		}
	};
};

DWORD WINAPI min_max(LPVOID lpParameter)
{
	try
	{
		ThreadData* data = static_cast<ThreadData*>(lpParameter);
		if (data->arr.empty())
		{
			throw runtime_error("Calculating error: The array is empty.");
		}
		data->minVal = data->arr[0];
		data->maxVal = data->arr[0];

		for (int i = 0; i < data->arr.size(); i++)
		{
			if (data->arr[i] < data->minVal)	data->minVal = data->arr[i];
			else								data->maxVal = data->arr[i];

			Sleep(7);
		}
		cout << "Min array element: \t" << data->minVal << "\nMax array element:\t" << data->maxVal << endl;
	}
	catch (const exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
		return 1;
	}
	return 0;
}

DWORD WINAPI average(LPVOID lpParameter)
{
	try
	{
		ThreadData* data = static_cast<ThreadData*>(lpParameter);
		if (data->arr.empty())
		{
			throw runtime_error("Division by zero: The array is empty.");
		}
		for (int i = 0; i < data->arr.size(); i++)
		{
			data->average += data->arr[i];
			Sleep(12);
		}
		data->average = data->average / data->arr.size();
		cout << "Average value of array elements:\t" << data->average << endl;
	}
	catch (const exception& e)
	{
		cout << "ERROR: " << e.what() << endl;
		return 1;
	}
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
