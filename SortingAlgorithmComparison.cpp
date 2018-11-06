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
	for(int size = 500; size <= 20000; size += 500)
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
	for(int size = 500; size <= 20000; size += 500)
	{
		comparisons = 0;
		arr = new int[size];//Allocate memory for array with size elements
		randomize(arr, size);//Initialize array with random values
		auto start = chrono::high_resolution_clock::now();//Start counting time
		
		insertionSort(arr, size, comparisons);//Call insertionSort to sort randomized array
		
		auto end = chrono::high_resolution_clock::now();//Stop counting time
		chrono::duration<float> time_elapsed = end - start;//Get time difference
		float time_taken = time_elapsed.count()*1000;//Time in milliseconds
		o << size << "," << time_taken << "," << comparisons << '\n';
		delete[] arr;//Free memory allocated for the array
	}
	o.close();
	/*Insertion sort testing complete*/	
	
	/*Test selection sort*/
	o.open("selectionSortResult.csv");
	for(int size = 500; size <= 20000; size += 500)
	{
		comparisons = 0;
		arr = new int[size];//Allocate memory for array with size elements
		randomize(arr, size);//Initialize array with random values
		auto start = chrono::high_resolution_clock::now();//Start counting time
		
		selectionSort(arr, size, comparisons);//Call selectionSort to sort randomized array
		
		auto end = chrono::high_resolution_clock::now();//Stop counting time
		chrono::duration<float> time_elapsed = end - start;//Get time difference
		float time_taken = time_elapsed.count()*1000;//Time in milliseconds
		o << size << "," << time_taken << "," << comparisons << '\n';
		delete[] arr;//Free memory allocated for the array
	}
	o.close();
	/*Selection sort testing complete*/	
	
	/*Test quick sort*/
	o.open("quickSortResult.csv");
	for(int size = 500; size <= 20000; size += 500)
	{
		comparisons = 0;
		arr = new int[size];//Allocate memory for array with size elements
		randomize(arr, size);//Initialize array with random values
		auto start = chrono::high_resolution_clock::now();//Start counting time
		
		quickSort(arr, 0, size - 1, comparisons);//Call quickSort to sort randomized array
		
		auto end = chrono::high_resolution_clock::now();//Stop counting time
		chrono::duration<float> time_elapsed = end - start;//Get time difference
		float time_taken = time_elapsed.count()*1000;//Time in milliseconds
		o << size << "," << time_taken << "," << comparisons << '\n';
		delete[] arr;//Free memory allocated for the array
	}
	o.close();
	/*Quick sort testing complete*/	
	
	/*Test merge sort*/
	o.open("mergeSortResult.csv");
	for(int size = 500; size <= 20000; size += 500)
	{
		comparisons = 0;
		arr = new int[size];//Allocate memory for array with size elements
		randomize(arr, size);//Initialize array with random values
		auto start = chrono::high_resolution_clock::now();//Start counting time
		
		mergeSort(arr, size, comparisons);//Call mergeSort to sort randomized array
		
		auto end = chrono::high_resolution_clock::now();//Stop counting time
		chrono::duration<float> time_elapsed = end - start;//Get time difference
		float time_taken = time_elapsed.count()*1000;//Time in milliseconds
		o << size << "," << time_taken << "," << comparisons << '\n';
		delete[] arr;//Free memory allocated for the array
	}
	o.close();
	/*Merge sort testing complete*/	
	
	return 0;
}
