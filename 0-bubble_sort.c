#include <stdio.h>
#include <sort.h>

/**
 * bubble_sort - function that sorts numbers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
