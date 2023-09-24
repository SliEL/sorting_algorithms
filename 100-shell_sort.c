#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * shell_sort - Sorts arrays of integers in ascending
 *              order using the shell sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
		return;

    while (gap < size / 3)
        gap = gap * 3 + 1;
    
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j = j - gap;
            }
            array[j] = temp;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}