#ifndef INSERTION_H
#define INSERTION_H

#include<iostream>

/*******************************************************	
*	Function: 	Perform insertion sort on given array
*	Input:		Array to sort and size of array
*	Output:		None
*******************************************************/
void insertionSort(int *arr, const int size, long long &comparisons)
{
	int val, j;
	for(int i = 1; i < size; i++)
	{
		val = arr[i];
		j = i - 1;
		/*Shift all elements which are greater then val on left side of arr[i] to right by one index*/
		while(val < arr[j] && j >= 0)
		{
			comparisons++;//Increment number of comparisons
			arr[j + 1] = arr[j];
			j--;
		}
		/*Insert val to it's appropriate position after shifting of elements*/
		arr[j + 1] = val;
	}
}

#endif
