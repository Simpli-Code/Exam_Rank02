/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:05:44 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:35:01 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
--------------------------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The strpbrk() function locates in the null-terminated string s the first
occurrence of any character in the string charset and returns a pointer
to this character.
If no characters from charset occur anywhere in s strpbrk() returns NULL.

The function should be prototyped as follows:
char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		int	i = 0;
		while (s2[i])
		{
			if (s2[i] == *s1)
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (0);
}

int main (void)
{
	// Array with string to search
	char str [] = "1234567890";

	// A set of characters that should not be included in the desired segment
	char sym [] = "9876";

	// Determine the length of the initial segment that does not contain the characters "9876"
	printf ("\"%s \"- A piece of the first line in which characters from the second line first appear. \n", ft_strpbrk (str, sym));

	return (0);
}
