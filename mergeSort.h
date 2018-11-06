#ifndef MERGE_H
#define MERGE_H

#include<iostream>

/**************************************************************************************************
*	Function:	To merge left and right sub-arrays into arr in sorted order.
*	Input:		Five parameters: left and right sub-arrays and their size and bigger array arr.
*	Output:		None.
**************************************************************************************************/
void merge(int *arr, int *left, int leftCount, int *right, int rightCount, long long &comparisons)
{
	int i = 0, j = 0, k = 0;
	/*Fill arr with elements from left and right sub-arrays in sorted order until one or both
	sub-arrays are exhausted*/
	while(i < leftCount && j < rightCount)
	{
		comparisons++;
		/*Merge in ascending order*/
		if(left[i] <= right[j])			/*Change to left[i] >= right[i] to sort in descending order*/
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	/*If all elements of right sub-array are merged into arr but left sub-array still not completely merged
	then merge left out elements of left sub-array into arr*/
	while(i < leftCount)
	{
		comparisons++;
		arr[k++] = left[i++];
	}
	/*If all elements of left sub-array are merged into arr but right sub-array still not completely merged
	then merge left out elements of right sub-array into arr*/
	while(j < rightCount)
	{
		comparisons++;
		arr[k++] = right[j++];
	}
}

/**************************************************************************************************************************
*	Function:	To divide arr into left and right sub-arrays and call merge function to merge left and right sub-arrays
*	Input:		Two parameters: Array to be divided and it's size.
*	Output:		None.
**************************************************************************************************************************/
void mergeSort(int *arr, int size, long long &comparisons)
{
	if(size < 2)
		return;
	int mid = size/2;
	/*Allocate memory for both sub-arrays*/
	int *left = new int[mid];
	int *right = new int[size - mid];
	/*Fill left sub-array*/
	for(int i = 0; i < mid; i++)
		left[i] = arr[i];
	/*Fill right sub-array*/
	for(int i = mid; i < size; i++)
		right[i - mid] = arr[i];
	/*Call mergeSort to further divide sub-arrays left and right*/
	mergeSort(left, mid, comparisons);
	mergeSort(right, size - mid, comparisons);
	merge(arr, left, mid, right, size - mid, comparisons);
	delete[] left;
	delete[] right;
}

#endif
