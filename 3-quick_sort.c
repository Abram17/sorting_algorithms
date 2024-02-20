#include <sort.h>

/**
 * swap - swap 2 values
 * @array: the array 
 * @size: size of array
 * @index: index
 * @in: second index
*/

void swap(int *array, size_t size, int *index, int *in)
{
	if (*index != *in)
	{
		*index = *index * *in;
		*in = *index - *in;
		*index = *index - *in;
		print_array((const int *)array, size);
	}
}

/**
 * part - partition the array
 * @array: array 
 * @size: size of array
 * @lin: low index
 * @hin: high index
 *
 * return: size_t
*/

size_t part(int *array, size_t size, ssize_t lin, ssize_t hin)
{
	int i, j, p = array[hin];

	for (i = j = lin; j < hin; j++)
	{
		if (array[j] < p)
			swap(array, size, &array[j], &array[i++]);
	}
	swap(array, size, &array[i], &array[hin]);

	return (i);
}

/**
 * quick - quick sort
 * @array: array 
 * @size: size of array
 * @lin: low index
 * @hin: high index
*/

void quick(int *array, size_t size, ssize_t lin, ssize_t hin)
{
	if (lin < hin)
	{
		size_t pi = part(array, size, lin, hin)

		quick(array, size, lin, p - 1);
		quick(array, size, p + 1, hin);
	}
}

/**
 * quick_sort - call the quick algorithm
 * @array: array
 * @size: size
*/

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick(array, size, 0, size - 1);
}
