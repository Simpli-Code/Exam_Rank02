/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:30:07 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:40:44 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int	*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	size = 0;

	if (start < end)
		size = end - start + 1;
	else
		size = start - end + 1;
	int	*arr = malloc(sizeof(int) * (size));
	int	i = 0;
	while (start <= end)
	{
		arr[i] = start;
		start++;
		i++;
	}
	while (start >= end)
	{
		arr[i] = start;
		start--;
		i++;
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	*arr;
	int size;

	if (argc == 3)
	{
		int start = atoi(argv[1]);
		int	end = atoi(argv[2]);
		if (start < end)
			size = end - start + 1;
		else
			size = start - end + 1;
		arr = ft_range(start, end);
		while (i < size)
		{
			printf("%d\t", arr[i]);
			i++;
		}
	}
	printf("\n");
	free(arr);
	return (0);
}
