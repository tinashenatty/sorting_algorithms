#include "sort.h"
#include <stdio.h>

void list_split_merge(int *array, int begin, int end, int *copy);
void top_down_merge(int *array, int beg, int mid, int end, int *copy);
void print_range(int *array, int start, int stop);

/**
* merge_sort - sorts a list using the merge sort algorithm
* @array: array to be sorted
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	list_split_merge(array, 0, size, copy);
	free(copy);
}


/**
* list_split_merge - recursively splits the list into individual elements.
* @array: list to split
* @begin: starting index
* @end: stopping index (exclusive)
* @copy: copy of the list
*
* Return void
*/
void list_split_merge(int *array, int begin, int end, int *copy)
{
	int middle;

	if (end - begin <= 1)
		return;
	middle = (begin + end) / 2;
	/* Recursively breaks down the range */
	list_split_merge(array, begin, middle, copy);
	list_split_merge(array, middle, end, copy);
	/*Recursively merges the broken ranges*/
	top_down_merge(copy, begin, middle, end, array);
}


/**
* top_down_merge - merges the array sublists whenever it is called
* @array: list to merge
* @beg: starting index
* @mid: middle index
* @end: stopping index (exclusive)
* @copy: copy of the list
*
* Return: void
*/
void top_down_merge(int *array, int beg, int mid, int end, int *copy)
{
	int i = beg, j = mid, k;

	printf("Merging...\n");
	printf("[Left]: ");
	print_range(copy, beg, mid);
	printf("\n");
	printf("[Right]: ");
	print_range(copy, mid, end);
	printf("\n");
	for (k = beg; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i += 1;
		}
		else
		{
			copy[k] = array[j];
			j += 1;
		}
	}
	for (k = beg; k < end; k++)
		array[k] = copy[k];
	printf("[Done]: ");
	print_range(copy, beg, end);
	printf("\n");
}

/**
* print_range - prints the elements of an array within a specified range.
* @array: array to print
* @start: starting point on the range
* @stop: stopping point on the range (exclusive)
*
* Return: void
*/
void print_range(int *array, int start, int stop)
{
	int i;

	for (i = start; i < stop; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
}
