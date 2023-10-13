/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:38:14 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:36:23 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <unistd.h>
#include <stdio.h>


int	max(int	*tab, unsigned int len)
{
	if (!len)
		return (0);
	int	i = 1;
	int	max = tab[0];

	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int	main(void)
{
	 int	arr[]={424, 39, 45, -98, 423, 780,};
	//int	arr[0];

	int len = sizeof(arr) / sizeof(arr[0]);

	int	maxi = max(arr, len);
	printf("%d\n", maxi);
	return (0);
}
