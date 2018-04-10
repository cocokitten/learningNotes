#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SortMethods
{
public:
	
	void BubbleSort(vector<int>& arr);                      //1冒泡排序
	void InsertionSort(vector<int>& arr);                   //2直接插入排序
	void SelectionSort(vector<int>&arr);                    //3选择排序
	
	void MaxHeapify(vector<int>&arr,int start,int end);     //4堆排序
	void HeapSort(vector<int>&arr);

	size_t PartSort(vector<int>&arr, int left, int right);  //5快速排序（递归）
	void QuickSort(vector<int>&arr,int left, int right);

	bool MergeSort(int a[], int n);    //6归并排序	

	void display(vector<int> arr);
	void swap(int &a, int &b);	
	
};
//--------------------------------------------------------------------------------
//冒泡排序
//时间复杂度:O(N^2)
void SortMethods::BubbleSort(vector<int>& arr)    
{
	int length = arr.size();
	bool flag = true; //标记，用于判断是否有序          
	for (int i = 0; i < length; i++)       //将大的记录“沉”下去
	{
		for (int j = 0; j < length-1-i; j++)
			if (arr[j] > arr[j + 1]) { 
				swap(arr[j], arr[j + 1]); 
				flag = false;     
		}
		if (flag) return; //表示有序，直接返回
	}
}
//--------------------------------------------------------------------------------
//直接插入排序
//时间复杂度:O(N^2)
void SortMethods::InsertionSort(vector<int>& arr) {    

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i]<arr[i-1])
		{
			int temp = arr[i];
			int j = 0;
			for (j = i-1; j >=0 && arr[j]>temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
//--------------------------------------------------------------------------------
//选择排序
//时间复杂度:O(N^2)
void SortMethods::SelectionSort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		int min = i;
		for (int j = i+1; j < arr.size(); j++) //在未排序列中找到一个最小值
		{
			if (arr[j]<arr[min])min = j;
		}
		swap(arr[i], arr[min]); //交换，将找出的最小值放置在正确的位置上
	}
}

//--------------------------------------------------------------------------------
//堆排序
//时间复杂度:O(N* lgN)
void SortMethods::MaxHeapify(vector<int>&arr, int start, int end) {
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1]) son++;
		if (arr[dad] > arr[son]) return;
		else
		{
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void SortMethods::HeapSort(vector<int>&arr) {
	int length = arr.size();

	for (int i = length / 2 - 1; i>= 0; i--)
		//
		MaxHeapify(arr, i, length - 1);
	for (int i = length-1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		MaxHeapify(arr, 0, i - 1);
	}
}
//--------------------------------------------------------------------------------
//快速排序
//时间复杂度:O(N* lgN)
//思想:
//第一趟排序，找出最后一个元素的对应位置，并将其放入该位置；
//以该元素分成两块空间，分别对其进行排序
//直到一块空间的元素不大于1时，结束

//第一趟排序(分区)
size_t SortMethods::PartSort(vector<int>&arr, int left, int right) {
	int pivotkey = arr[right];

	while (left < right)
	{
		while (left < right && arr[left] <= pivotkey) left++;
		arr[right] = arr[left];
		
		while (left < right && arr[right] >= pivotkey) right--;
		arr[left] = arr[right];
	}
	arr[left] = pivotkey;
	return left;
}
//之后对左右子序列递归排序，最终得到有序序列。
void SortMethods::QuickSort(vector<int>&arr,int left,int right) {

	if (left < right)
	{
		int mid = PartSort(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid+1, right);
	}
}
//--------------------------------------------------------------------------------
//归并排序
//最坏时间复杂度:O(N* lgN)
//最优时间复杂度:O(N)
//平均时间复杂度:O(N* lgN)

//空间复杂度:O(N)
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);         //左边有序
		mergesort(a, mid + 1, last, temp);      //右边有序
		mergearray(a, first, mid, last, temp);  //再将二个有序数列合并
	}
}
bool SortMethods::MergeSort(int a[], int n) {

	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}
//--------------------------------------------------------------------------------
void SortMethods::display(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void SortMethods::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
//--------------------------------------------------------------------------------
int main() {

	SortMethods a;
	vector<int> arr = { 3,7,1,0,4,6,9,2,2,1 };

	//a.BubbleSort(arr);
	//a.InsertionSort(arr);
	//a.SelectionSort(arr);
	//a.HeapSort(arr);
	a.QuickSort(arr, 0, (arr.size() - 1)); 
	a.display(arr);

    return 0;
}
