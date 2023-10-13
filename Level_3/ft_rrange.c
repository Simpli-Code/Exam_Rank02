/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:30:19 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:58:23 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int	*ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	size;

	if (start < end)
		size = end - start + 1;
	else
		size = start - end + 1;
	int	*arr = malloc(sizeof(int) * size);
	int	i = 0;
	while (end <= start)
	{
		arr[i] = end;
		end++;
		i++;
	}
	while (end >= start)
	{
		arr[i] = end;
		end--;
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
		arr = ft_rrange(start, end);
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
