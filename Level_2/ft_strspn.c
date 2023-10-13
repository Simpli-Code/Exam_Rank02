/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:33:35 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:35:31 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strspn() function calculates the length of the initial substring of a string
that consists only of characters from a specified set.
It returns the length of the matching substring.
The counting stops when a character is encountered in the input string that is not
present in the set, or when the end of the input string is reached.
--------------------------------------------------------------------------------
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
--------------------------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
(man strspn).
The function should be prototyped as follows:
size_t	ft_strspn(const char *s, const char *accept);
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	j;
	int	i = 0;
	const char *p = s;
	const char *set = accept;

	while (p[i])
	{
		j = 0;
		while (set[j] && set[j] != p[i])
			j++;
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int main()
{
	const char *s = "abcdexyz1";
	const char *set = "abcdefghijklmnopqrstuvwxyz";

	size_t length = ft_strspn(s, set);
	printf("Length of the initial substring: %zu\n", length);

	return 0;
}
