// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <windows.h>
#include <iostream>
using namespace std;

//定义两个全局变量，用来计数
int g_iCount1 = 0;
int g_iCount2 = 0;
//定义一个全局变量，用来控制while循环
int g_iFlag = 1;
//下面函数不断让变量g_iCount1和g_iCount2自加1
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	while (g_iFlag)
	{
		g_iCount1++;
		g_iCount2++;
	}
	return 0;
}
int main(void)
{
	HANDLE hThread[2];
	hThread[0] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
	hThread[1] = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
	Sleep(100);
	//修改全局标志位使两个线程停止运行
	g_iFlag = 0;
	printf("g_iCount1 = %d\n", g_iCount1);
	printf("g_iCount2 = %d\n", g_iCount2);
	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	system("pause");
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
