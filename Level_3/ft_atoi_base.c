/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:18:28 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 09:53:29 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	get_nbr(char c, int base)
{
	int	max;

	if (base <= 10)
		max = base + '0';
	else
		max = base - 10 + 'a';
	if (c >= '0' && c <= '9' && c < max)
		return (c - '0');
	else if (c >= 'a' && c <= 'z' && c < max)
		return (c - 'a' + 10);
	else
		return (-1);
}

int	ft_atoi_base(const char *s, int base)
{
	int	i = 0;
	int	nbr = 0;
	int	sum = 0;
	int	sign = 1;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((nbr = get_nbr(to_lower(s[i]), base)) >= 0)
	{
		sum = (sum * base) + (sign * nbr);
		i++;
	}
	return (sum);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("ff", 16));
}
