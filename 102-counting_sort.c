#include "sort.h"

/**
 * find_max - find max element on an array
 * @array: array of integers
 * @size: size of the array.
 * Return: The maximum integer in the array.
*/

int find_max(int *array, int size)
{
    int i, max;

    max = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * counting_sort - sorting an array of integeres
 *              using the counting algorithm in ascending
 *              order.
 * @array: The array to sort.
 * @size: size of the array to sort.
 * 
 * Description: Print the sorted array.
*/

void counting_sort(int *array, size_t size)
{
    int i, max, *count, *sorted;

    if (array == NULL || size < 2)
        return;
    
    sorted = malloc(sizeof(int) * size);
    if (!sorted)
        return;
    
    max = find_max(array, size);
    count = malloc(sizeof(int) * (max + 1));
    if (!count)
    {
        free(sorted);
        return;
    }

    for (i = 0; i < (max + 1); i++)
        count[i] = 0;
    

    for (i = 0; i < (int) size; i++)
        count[array[i]] += 1;
    
    for (i = 0; i < (max + 1); i++)
        count[i] += count[i - 1];
    print_array(count, (max + 1));

    for (i = 0; i < (int) size; i++)
    {
        sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}