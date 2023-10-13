/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:55:23 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:25:48 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
--------------------------------------------------------------------------------
Reproduce exactly the behavior of the function strcspn
(man strcspn).
The function should be prototyped as follows:
size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	j;
	int	i = 0;
	const char	*p = s;
	const char	*set = reject;

	while (p[i])
	{
		j = 0;
		while (set[j])
		{
			if (p[i] == set[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main()
{
	const char* str = "123abcxyz";
	const char* set = "abcdefghijklmnopqrstuvwxyz";

	size_t length = ft_strcspn(str, set);
	printf("Length of the initial substring: %zu\n", length);

	return 0;
}
