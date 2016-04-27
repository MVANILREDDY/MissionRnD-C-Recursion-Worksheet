/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiral_trav(int * arr, int row, int col, int rows, int cols, int round, int ** input_array, int i, char direction);
void spiral_trav(int * arr, int row, int col, int rows, int cols, int round, int ** input_array, int i, char direction)
{
	if (direction == 'l')
	{
		arr[i] = input_array[row][col];
		i++;
		if (col != cols - round - 1)
			spiral_trav(arr, row, col + 1, rows, cols, round, input_array, i, 'l');
		else{
			if (row == rows - round - 1)
				return;
			spiral_trav(arr, row + 1, col, rows, cols, round, input_array,i, 'b');
		}
		return;
	}
	else if (direction == 'b'){
		arr[i] = input_array[row][col];
		i++;
		if (row != rows - round - 1)
			spiral_trav(arr, row + 1, col, rows, cols, round, input_array, i, 'b');
		else{
			if (col == round)
				return;
			spiral_trav(arr, row, col - 1, rows, cols, round, input_array, i, 'r');
		}
		return;
	}
	else if (direction == 'u')
	{
		arr[i] = input_array[row][col];
		i++;
		if (row != round + 1)
			spiral_trav(arr, row - 1, col, rows, cols, round, input_array, i, 'u');
		else{
			if (col == cols - round - 1)
				return;
			spiral_trav(arr, row, col + 1, rows, cols, round + 1, input_array, i, 'l');
		}
		return;
	}
	else
	{
		arr[i] = input_array[row][col];
		i++;
		if (col != round)
			spiral_trav(arr, row, col - 1, rows, cols, round, input_array, i, 'r');
		else{
			if (row == round)
				return;
			spiral_trav(arr, row - 1, col, rows, cols, round, input_array, i, 'u');
		}
		return;
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int * arr = (int *)malloc(sizeof(int)*rows*columns);
	spiral_trav(arr, 0, 0, rows, columns, 0, input_array, 0, 'l');
	return arr;
}