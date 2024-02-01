#ifndef QUICKSORT_H
#define QUICKSORT_H
#include<iostream>
using namespace std;
int partition1(int arr[], int first, int last)
{
	int pivot = arr[first];
	int right = first;
	int left = last;
	while (right < left)
	{
		do
		{
			right++;
		} while (arr[right] <= pivot);
		do
		{
			left--;
		} while (arr[left] > pivot);

		if (right < left)
			swap(arr[right], arr[left]);
	}
	swap(arr[first], arr[left]);
	return left;
}

void quickSort1(int arr[], int first, int last)
{

	if (first < last) {
		int piv = partition1(arr, first, last);
		quickSort1(arr, first, piv);
		quickSort1(arr, piv + 1, last);
	}

}



int partition2(int arr[], int iBegin, int jEnd) {
	int right = iBegin;
	int left = jEnd;
	int pivLoc = right;
	while (true)
	{
		while (arr[pivLoc] <= arr[left] && pivLoc != left)
		{
			left--;
		}
		if (pivLoc == left)
			break;
		else if (arr[pivLoc] > arr[left])
		{
			swap(arr[left], arr[pivLoc]);
			pivLoc = left;
		}

		while (arr[pivLoc] >= arr[right] && pivLoc != right)
		{
			right++;
		}
		if (pivLoc == right)
			break;
		else if (arr[pivLoc] < arr[right])
		{
			swap(arr[right], arr[pivLoc]);
			pivLoc = right;
		}
	}
	return pivLoc;
}


void quickSort2(int arr[], int first, int last)
{

	if (first < last) {
		int piv = partition2(arr, first, last);
		quickSort2(arr, first, piv - 1);
		quickSort2(arr, piv + 1, last);
	}

}


#endif // QUICKSORT_H