#include<threads.h>
#include<windows.h>
#include<ThreadData.h>
#include<iostream>

using namespace std;

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
