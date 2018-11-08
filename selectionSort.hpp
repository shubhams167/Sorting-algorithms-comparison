#ifndef SELECTION_H
#define SELECTION_H

#include<iostream>

/*******************************************************	
*	Function: 	Perform selection sort on given array
*	Input:		Array to sort and size of array
*	Output:		None
*******************************************************/
void selectionSort(int *arr, const int size, long long &comparisons)
{
	int min, temp;
	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		/*Find index of minimum element in unsorted part of array*/
		for(int j = i + 1; j < size; j++)
		{
			comparisons++;
			if(arr[j] < arr[min])
				min = j;
		}
		/*Swap minimum element with first element in unsorted part of array*/
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

#endif
