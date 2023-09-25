#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1


/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* ##### bubble sort ############ */
void swap_ints(int *a, int *b);
void bubble_sort(int *array, size_t size);

/*##### insertion sort ########## */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void insertion_sort_list(listint_t **list);


/* ##### selection sort ######## */
void selection_sort(int *array, size_t size);

/* ##### Quick sort ########## */
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/* ##### shell Sort ############## */
void shell_sort(int *array, size_t size);

/* ##### Counting Sort ######### */
void counting_sort(int *array, size_t size);
int find_max(int *array, int size);

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

#endif /* SORT_H */