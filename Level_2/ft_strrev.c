/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:07:12 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:30:11 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <unistd.h>
#include <stdio.h>

char	*ft_strrev(char *s)
{
	int	i = 0;
	int	j = 0;
	int	tmp = 0;

	while (s[j])
		j++;
	while (i < j)
	{
		j--;
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
	}
	return (s);
}

void	ft_putstr(char *s)
{
	int	i = 0;

	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_putstr(ft_strrev(argv[1]));
	}
	write (1, "\n", 1);
	return (0);
}
