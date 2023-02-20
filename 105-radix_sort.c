#include "sort.h"


/**
* get_max - returns the value of the largest element in the array.
* @array: array to be evaluated.
* @size: size of array to be evaluated.
*
* Return: value of largest element.
*/
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}


/**
* radix_sort - sorts the contents of the array using radix sort algorithm.
* @array: array to sort.
* @size: size of array to sort.
*
* Return: void
*/
void radix_sort(int *array, size_t size)
{
	int *count, *result, max, digit = 1;
	long arr_size, i;

	arr_size = size;
	max = get_max(array, arr_size);
	count = malloc(sizeof(int) * 10);
	result = malloc(sizeof(int) * arr_size);
	if (!count || !result)
		return;
	while (max / digit > 0)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < arr_size; i++)
			result[i] = 0;
		/* Main Algorithm */
		for (i = 0; i < arr_size; i++)
			count[(array[i] / digit) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = arr_size - 1; i >= 0; i--)
		{
			result[count[(array[i] / digit) % 10] - 1] = array[i];
			count[(array[i] / digit) % 10]--;
		}
		for (i = 0; i < arr_size; i++)
			array[i] = result[i];
		digit *= 10;
		print_array(array, arr_size);
	}
	free(count);
	free(result);
}
