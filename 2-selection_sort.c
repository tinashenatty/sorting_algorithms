#include "sort.h"


/**
* selection_sort - sorts an array using the selection sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_index;
	int swap;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min_index = j - 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}
		/* Swaps the two elements */
		swap = array[i];
		array[i] = array[min_index];
		array[min_index] = swap;
		/* Prints out the reorganized array to the screen. */
		print_array(array, size);
		i++;
	}
}
