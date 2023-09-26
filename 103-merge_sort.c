#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t right, size_t mid,
		size_t left);
void merge_sort_recursive(int *subarr, int *buff, size_t right, size_t left);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @right: The right most index of the array.
 * @mid: The middle index of the array.
 * @left: The left most index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t right, size_t mid,
		size_t left)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + right, mid - right);

	printf("[right]: ");
	print_array(subarr + mid, left - mid);

	for (i = right, j = mid; i < mid && j < left; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < left; j++)
		buff[k++] = subarr[j];
	for (i = right, k = 0; i < left; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + right, left - right);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm with recursion.
 * @subarr: A subarray of integers to sort.
 * @buff: A buffer where to store the sorted result.
 * @right: The right most index of the subarray.
 * @left: The left most index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t right, size_t left)
{
	size_t mid;

	if (left - right > 1)
	{
		mid = right + (left - right) / 2;
		merge_sort_recursive(subarr, buff, right, mid);
		merge_sort_recursive(subarr, buff, mid, left);
		merge_subarr(subarr, buff, right, mid, left);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using Merge Sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}