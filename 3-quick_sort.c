#include "sort.h"

void quick_sort_helper(int *array, long lo, long hi, size_t size);
long partition(int *array, long lo, long hi, size_t size);

/**
* quick_sort - sorts the contents of an array using quick sort.
* @array: array to sort
* @size: size of array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}

/**
* quick_sort_helper - helps perform the recursive portion of the quick sort.
* @array: array to sort
* @lo: beginning index
* @hi: ending index
*
* Return: void
*/
void quick_sort_helper(int *array, long lo, long hi, size_t size)
{
	long p;

	if (lo >= hi)
		return;
	p = partition(array, lo, hi, size);
	quick_sort_helper(array, lo, p - 1, size);
	quick_sort_helper(array, p + 1, hi, size);
}

/**
* partition - partitions the array during quick sort.
* @array: array to partition
* @lo: beginning index
* @hi: ending index
*
* Return: index of partition
*/
long partition(int *array, long lo, long hi, size_t size)
{
	long i, j;
	int pivot;
	int swap;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			swap = array[i];
			array[i] = array[j];
			array[j] = swap;
		}
	}
	i += 1;
	swap = array[i];
	array[i] = array[hi];
	array[hi] = swap;
	print_array(array, size);
	return (i);
}
