#include<gtest/gtest.h>
#include"threads.h"
#include"ThreadData.h"
#include<windows.h>

TEST(ThreadTests, TestMinMax)
{
	ThreadData* data = new ThreadData (5);
	data->arr = { 0, 1, 2, 3, 4 };
	HANDLE hThread = CreateThread(NULL, 0, min_max, data, 0, NULL);
	ASSERT_NE(hThread, nullptr);

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	EXPECT_EQ(data->minVal, 0);
	EXPECT_EQ(data->maxVal, 4);
}

TEST(ThreadTests, TestAverage)
{
	ThreadData* data = new ThreadData(4);
	data->arr = { 2, 4, 6, 12 };
	HANDLE hThread = CreateThread(NULL, 0, average, data, 0, NULL);
	ASSERT_NE(hThread, nullptr);

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	EXPECT_EQ(data->average, 6);
}