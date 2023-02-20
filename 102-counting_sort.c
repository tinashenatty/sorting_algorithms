#include "sort.h"

size_t determine_max(int *array, size_t size);
/**
* counting_sort - sorts the contents of an array using counting sort algorithm
* @array: array to sort
* @size: size of array to sort
*
* Return: void
*/
void counting_sort(int *array, size_t size)
{
	int *input, *count;
	size_t i, j, max;
	long iter, index;

	max = determine_max(array, size);
	/* Create count array */
	count = malloc(sizeof(int) * (max + 1));
	input = malloc(sizeof(int) * (size));
	if (!count || !input)
		return;
	/* Creating a copy of the array */
	for (i = 0; i < size; i++)
		input[i] = array[i];
	/* main algorithm */
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		j = input[i];
		count[j] += 1;
	}
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, (max + 1));
	for (iter = (size - 1); iter >= 0; iter--)
	{
		j = input[iter];
		count[j] -= 1;
		index = count[j];
		array[index] = input[iter];
	}
	free(count), free(input);
}

/**
* determine_max - determines the maximum element in the sequence.
* @array: sequence to evaluate
* @size: size of sequence
*
* Return: maximum element
*/
size_t determine_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (max < array[i])
			max = array[i];
	return (max);
}
