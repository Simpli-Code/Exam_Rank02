/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:36:28 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:14:25 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	word_len(char *s)
{
	int	i = 0;

	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		i++;
	return (i);
}

char	*word_dupli(char *s)
{
	int	i = 0;
	int	len = word_len(s);
	char *word = malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

void	fill_array(char **arr, char *s)
{
	int	i = 0;
	int	j = 0;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i])
	{
		arr[j] = word_dupli(s + i);
		j++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
}

int	word_count(char *s)
{
	int	count = 0;
	int	i = 0;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i])
	{
		count++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	return (count);
}

char	**ft_split(char *s)
{
	int	count = word_count(s);
	char **arr = malloc(sizeof(char *) * (count + 1));
	arr[count] = 0;
	fill_array(arr, s);
	return (arr);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	char **splited;

	if (argc == 2)
	{
		splited = ft_split(argv[1]);
		while (splited[i])
		{
			printf("%s\n", splited[i]);
			free(splited[i]);
			i++;
		}
		free(splited);
	}
	else
		printf("\n");
	return (0);
}
