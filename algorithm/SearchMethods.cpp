// SearchMethod.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

class SearchMethod
{
public:
	int BinarySearch(int a[], int value, int n);
	int BinarySearch_recursive(int a[], int value, int low, int high);
};
//======================================================================

//二分查找
//元素必须是有序的，如果是无序的则要先进行排序操作
int SearchMethod::BinarySearch(int a[], int value, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low < high)
	{
		if (a[mid] == value)return mid;
		else
		{
			if (a[mid] > value) high = mid - 1;
			if (a[mid] < value) low = mid + 1;
			mid = (low + high) / 2;
		}
	}
	return -1;
}
int SearchMethod::BinarySearch_recursive(int a[], int value, int low, int high) 
{
	if (low > high) return -1; //不加该句，查找的value不存在会出错!!

	int mid = (low + high) / 2;
	if (a[mid] == value) return mid;
	if (a[mid] > value) return BinarySearch_recursive(a, value, low, mid - 1);
	if (a[mid] < value) return BinarySearch_recursive(a, value, mid+1, high);
}
//-----------------------------------------------------------------------------

int main()
{
	int a[7] = { 2,0,1,4,9,6,3 };
	SearchMethod s;
	cout<<s.BinarySearch_recursive(a, 7, 0, 6);
	system("pause");
    return 0;
}

