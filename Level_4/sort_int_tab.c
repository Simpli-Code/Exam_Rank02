/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:20:41 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:42:24 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

#include <stdio.h>
#include <unistd.h>

int	ascending(int a, int b)
{
	return (a <= b);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i = 0;

	while (i < size - 1)
	{
		if (!ascending(tab[i], tab[i+1]))
		{
			int	tmp = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = tmp;
			i = -1;
		}
		i++;
	}
}



// The below functions are not required!!! It is just for testing purposes.

int	main(void)
{
	size_t	i = 0;
	int	arr[]={99, 2, 45, -9, 0};
	unsigned int	size = sizeof(arr) / sizeof(arr[0]);

	int	j = 0;
	printf("Before\t");
	while (j < size)
	{
		printf("%d\t", arr[j]);
		j++;
	}
	printf("\n");

	sort_int_tab(arr, size);
	printf("After\t");
	while (i < size)
	{
		printf("%d\t", arr[i]);
		i++;
	}
	printf("\n");
}
