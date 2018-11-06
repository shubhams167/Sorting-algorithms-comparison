#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<chrono>
#include "selectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "mergeSort.h"

using namespace std;

/*Function to initialize array with random values*/
void randomize(int *arr, const int &size)
{
	for(int i = 0; i < size; i++)
		arr[i] = rand();//Initialize array with random values
}

int main()
{
	srand(time(NULL));//Seed for random numbers generator rand()
	ofstream o;
	int *arr;
	long long comparisons;
	
	/*Test bubble sort*/
	o.open("bubbleSortResult.csv");
	for(int size = 500; size <= 10000; size += 500)
	{
		comparisons = 0;
		arr = new int[size];//Allocate memory for array with size elements
		randomize(arr, size);//Initialize array with random values
		auto start = chrono::high_resolution_clock::now();//Start counting time
		
		bubbleSort(arr, size, comparisons);//Call bubbleSort to sort randomized array
		
		auto end = chrono::high_resolution_clock::now();//Stop counting time
		chrono::duration<float> time_elapsed = end - start;//Get time difference
		float time_taken = time_elapsed.count()*1000;//Time in milliseconds
		o << size << "," << time_taken << "," << comparisons << '\n';
		delete[] arr;//Free memory allocated for the array
	}
	o.close();
	/*Bubble sort testing complete*/
	
	/*Test insertion sort*/
	o.open("insertionSortResult.csv");
	for(int size = 500; size <= 10000; size += 500)
	{
		comparisons = 0;
		arr = new int[size];//Allocate memory for array with size elements
		randomize(arr, size);//Initialize array with random values
		auto start = chrono::high_resolution_clock::now();//Start counting time
		
		insertionSort(arr, size, comparisons);//Call bubbleSort to sort randomized array
		
		auto end = chrono::high_resolution_clock::now();//Stop counting time
		chrono::duration<float> time_elapsed = end - start;//Get time difference
		float time_taken = time_elapsed.count()*1000;//Time in milliseconds
		o << size << "," << time_taken << "," << comparisons << '\n';
		delete[] arr;//Free memory allocated for the array
	}
	o.close();
	/*Insertion sort testing complete*/	
	
	return 0;
}
