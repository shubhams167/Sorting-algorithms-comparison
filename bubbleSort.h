#ifndef BUBBLE_H
#define BUBBLE_H

#include<iostream>

/*******************************************************	
*	Function: 	Perform bubble sort on given array
*	Input:		Array to sort and size of array
*	Output:		None
*******************************************************/
void bubbleSort(int *a, const int n, long long &comparisons)
{
	int flag = 1, temp;
	while(flag == 1)
	{
		flag = 0;
		for(int i = 0; i < n - 1; i++)
		{
			comparisons++;			
			if(a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				flag = 1;
			}
		}
	}
}

#endif
