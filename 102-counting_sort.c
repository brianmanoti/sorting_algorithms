#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Allocate memory for an array, using calloc
 *
 * @nmemb: Number of elements to allocate
 * @size: Size of each element
 *
 * Return: Pointer to the allocated memory, or NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * counting_sort - Sort an array of integers in ascending order using the
 *                 counting sort algorithm
 *
 * @array: The array of integers to sort
 * @size: The size of the array
 *
 * Description: This function implements the counting sort algorithm, which
 *              sorts an array of integers by counting the number of occurrences
 *              of each value in the array, and then using those counts to
 *              construct a sorted version of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i;
	int *counts, *output;

	if (!array || size < 2)
		return;

	/* Find the maximum element in the array */
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	/* Allocate memory for the counts and output arrays */
	counts = _calloc(max + 1, sizeof(int));
	output = _calloc(size, sizeof(int));

	if (!counts || !output)
		return;

	/* Count the occurrences of each value in the array */
	for (i = 0; i < (int)size; i++)
		counts[array[i]]++;

	/* Compute the cumulative counts */
	for (i = 1; i <= max; i++)
		counts[i] += counts[i - 1];

	/* Use the counts to place each element in the output array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		output[counts[array[i]] - 1] = array[i];
		counts[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	/* Free the temporary memory */
	free(counts);
	free(output);
}

