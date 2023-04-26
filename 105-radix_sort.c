#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - A utility function to get maximum value in arr[]
 * @arr: array
 * @n: size of the array
 * Return: maximum value in the array
 */
int getMax(int *arr, int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

/**
 * countSort - A function to do counting sort of arr[] according to
 * the digit represented by exp.
 * @arr: array to sort
 * @n: size of the array
 * @exp: exponent for the current digit place
 * @output: temporary output array
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
    int i, count[10] = { 0 };

    for (i = 0; i < (int)n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)n; i++)
    {
        arr[i] = output[i];
    }
}

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int *output;
    int exp, maximum;

    if (array == NULL || size < 2)
        return;

    maximum = getMax(array, size);
    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (exp = 1; maximum / exp > 0; exp *= 10)
    {
        countSort(array, size, exp, output);
        print_array(array, size);
    }

    free(output);
}

