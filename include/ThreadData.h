#pragma once

#include<vector>
struct ThreadData
{
	std::vector<int>arr;
	int minVal, maxVal;
	double average;

	ThreadData(int size) : minVal(-1), maxVal(-1), average(0.0)
	{
		if (size <= 0)
		{
			arr.resize(0);
		}
		else
		{
			arr.resize(size);
		}
	};
};