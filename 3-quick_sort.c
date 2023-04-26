#include "sort.h"

/**
 * swap - swap two elements in an array
 * @array: the array
 * @index1: the first index
 * @index2: the second index
 */
void swap(int *array, ssize_t index1, ssize_t index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme implementation
 * @array: the array
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 * Return: the final position of the pivot
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(array, i, j);
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        swap(array, i + 1, high);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quicksort - sort an array using quicksort algorithm
 * @array: the array to sort
 * @low: the lowest index of the array
 * @high: the highest index of the array
 * @size: the size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        ssize_t p = lomuto_partition(array, low, high, size);

        quicksort(array, low, p - 1, size);
        quicksort(array, p + 1, high, size);
    }
}

/**
 * quick_sort - sort an array using the quicksort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

