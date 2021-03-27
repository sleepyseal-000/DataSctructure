// Homework1-3DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
using namespace std;
//find the index of minimun element 
int minIndex(int a[], int i)
{
	if (i == 0) return 0;
	int j = minIndex(a, i - 1);
	if (a[i - 1] < a[j]) return i - 1;
	return j;
}
void mySwap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
//  Insertion sort
void insertionSort(int* a, int size)
{
	if (size == 1) return;
	int j = minIndex(a, size);
	if (j != 0) mySwap(*a, a[j]);
	insertionSort(++a, size - 1);
}

//Bubble sort 
void bubbleSort(int a[], int size) {
	int temp;

	// See notes
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}
// selection sort
void selectionSort(int a[], int size) {
	int temp, lowest;
	for (int i = 0; i < size - 1; i++) {
		lowest = i;
		for (int j = i; j < size; j++)
			if (a[j] < a[lowest])
				lowest = j;
		temp = a[i];
		a[i] = a[lowest];
		a[lowest] = temp;
	}

}

int main()
{
	const int row = 4;
	const int col = 3;
	const int size = row * col;
	/*
	Create a sort for 2d matrices. Do a bubble sort, insertion sort, and selection sort
	variation of this. Do NOT convert the matrix into a 1D array to sort. You must sort it as a
	2D structure
	
	*/
	//Create 2D matrices

	 int my2DM[row][col] =
		{{3, 1, 3},
		{7, 1, 9},
		{9, 1, 3},
		{9, 10, 4}};
		
	//insertionSort(my2DM[0], size);
	 bubbleSort(my2DM[0], size);
	 ///selectionSort(my2DM[0], size);
	// display array values
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << my2DM[i][j] << " ";
		}
		cout << endl;
	}



		
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
