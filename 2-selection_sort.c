#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - Write a function that will sort an array of integers
 * in an ascending order using with the help of Selection sort algorithm.
 * @array: The array to be printed
 * @size: Number of elements in the array
 *
 * Return: void
 */


void selection_sort(int *array, size_t size)
{
	size_t num1, num2, temp, min;

	if (array == NULL || size < 2)
		return;

	for (num1 = 0; num1 < size - 1; num1++)
	{
		min = num1;
		for (num2 = num1 + 1; num2 < size; num2++)
		{
			if (array[num2] < array[min])
				min = num2;
		}
		if (min != num1)
		{
			temp = array[min];
			array[min] = array[num1];
			array[num1] = temp;
			print_array(array, size);
		}
	}
}
