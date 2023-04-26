#include "sort.h"

/**
 * swap - swap the positions of two elements in an array
 * @array: array of integers
 * @item1: index of the first item
 * @item2: index of the second item
 */
void swap(int *array, int item1, int item2)
{
	/* Store the value of the first item in a temporary variable */
	int tmp = array[item1];

	/* Set the value of the first item to the value of the second item */
	array[item1] = array[item2];

	/* Set the value of the second item to the value of the temporary variable */
	array[item2] = tmp;
}

/**
 * shell_sort - sort an array of integers in ascending order using the Shell sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	/* Initialize the gap variable to 1 */
	size_t gap = 1;

	/* Initialize the index variable to 0 */
	size_t index = 0;

	/* If the array is NULL or the size is less than 2, return */
	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap value using the Knuth sequence */
	while (gap < size / 3)
		gap = 3 * gap + 1;

	/* Loop through the gap sequence */
	while (gap >= 1)
	{
		/* Loop through the array from the gap index to the end */
		for (size_t i = gap; i < size; i++)
		{
			/* Loop through the array from the current index to the gap index */
			for (index = i; index >= gap && array[index] < array[index - gap]; index -= gap)
			{
				/* Swap the current item with the item at the gap index */
				swap(array, index, index - gap);
			}
		}

		/* Print the current state of the array */
		print_array(array, size);

		/* Update the gap value */
		gap /= 3;
	}
}

