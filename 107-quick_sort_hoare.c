#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: The array to swap elements in.
 * @item1: The index of the first element.
 * @item2: The index of the second element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * hoare_partition - Uses the Hoare partition scheme to partition an array.
 * @array: The array to partition.
 * @first: The index of the first element.
 * @last: The index of the last element.
 * @size: The size of the array.
 * Return: The position of the last element sorted.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int pivot = array[last];
	int i = first - 1, j = last + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * qs - Sorts an array using the quicksort algorithm.
 * @array: The array to sort.
 * @first: The index of the first element.
 * @last: The index of the last element.
 * @size: The size of the array.
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the quicksort algorithm and the Hoare partition scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs(array, 0, size - 1, size);
}

