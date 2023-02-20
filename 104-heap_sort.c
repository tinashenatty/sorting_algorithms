#include "sort.h"


void swap(int *a, int *b);
void heapify(int *array, size_t count);
void sift_down(int *array, long start, long end, size_t count);

/**
* heap_sort - sorts the contents of an array using the heap sort algorithm.
* @array: array to sort
* @size: size of array to sort
*
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	long end;

	/* Builds max heap from array */
	heapify(array, size);
	/* Gets index of last element in array */
	end = size - 1;
	while (end > 0) /* While we have more than 1 unsorted element in array*/
	{
		/* Extracts the first element on the heap */
		swap(&array[end], &array[0]);
		print_array(array, size);
		/* Reduces the range of the heap within the array */
		end -= 1;
		/* Restores the heap */
		sift_down(array, 0, end, size);
	}
}

/**
* swap - swaps the values of two variables.
* @a: first variable.
* @b: second variable.
*
* Return: void
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
* heapify - converts an array into a max heap.
* @array: array to convert.
* @count: count of elements in the array.
*
* Return: void
*/
void heapify(int *array, size_t count)
{
	long end, start;

	end = count - 1;
	start = (end - 1) / 2;
	while (start >= 0)
	{
		sift_down(array, start, end, count);
		start -= 1;
	}
}

/**
* sift_down - helps 'heapify' create max heap using the sift down approach.
* @array: array to convert to heap.
* @start: starting point
* @end: ending point.
* @count: number of elements in the array
*
* Return: void
*/
void sift_down(int *array, long start, long end, size_t count)
{
	long root, child, to_swap;

	root = start;
	to_swap = root;
	child = 2 * root + 1;
	while (child <= end)
	{
		if (array[to_swap] < array[child])
			to_swap = child;
		if ((child + 1 <= end) && (array[to_swap] < array[child + 1]))
			to_swap = child + 1;
		if (to_swap == root)
		{
			return;
		}
		else
		{
			swap(&array[to_swap], &array[root]);
			print_array(array, count);
			root = to_swap;
			child = 2 * root + 1;
		}
	}
}
