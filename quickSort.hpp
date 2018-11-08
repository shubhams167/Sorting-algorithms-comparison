#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<iostream>

/**************************************************************************************************
*	Function:	Swaps passed formal arguments.
*	Input:		Two parameters: Two pointer-to-int to store address of two variables passed.
*	Output:		None.
**************************************************************************************************/
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

/**************************************************************************************************
*	Function:	Creates partition around pivot element.
*	Input:		Three parameters: Array to partition, left index and right index
*	Output:		Index of sorted pivot element.
**************************************************************************************************/
int partition(int *a, int left, int right, long long &comparisons)
{
	int pivot = a[right];//Select last element as pivot
	int i = left - 1;
	for(int j = left; j < right; j++)
	{
		comparisons++;
		if(a[j] <= pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);//Swap pivot element with a[i + 1]
	return i + 1;
}

/**************************************************************************************************
*	Function:	To perform quick sort on array. 
*	Input:		Three parameters: Array to sort, left and right index of array.
*	Output:		None.
**************************************************************************************************/
void quickSort(int *a, int left, int right, long long &comparisons)
{
	int j;
	if(left < right)
	{
		comparisons++;
		j = partition(a, left, right, comparisons);
		quickSort(a, left, j - 1, comparisons);
		quickSort(a, j + 1, right, comparisons);
	}
}

#endif
