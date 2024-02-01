#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<iostream>
using namespace std;
void heapify(int arr[], int size, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	if (l<size && arr[l]>arr[max])
		max = l;
	if (r<size && arr[r]>arr[max])
		max = r;

	if (max != i) {
		swap(arr[i], arr[max]);
		heapify(arr, size, max);
	}
}

void buildHeap(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
}

void heapSort(int arr[], int size)
{

	buildHeap(arr, size);
	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

}

#endif // HEAPSORT_H