/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:57:36 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:26:03 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	int	len = 0;

	while (src[len])
		len++;
	char *cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);

	cpy[len] = '\0';
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s", ft_strdup(argv[1]));
	}
	printf ("\n");
	return (0);
}
