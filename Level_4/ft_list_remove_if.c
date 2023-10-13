/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:19:07 by cha               #+#    #+#             */
/*   Updated: 2023/10/13 10:42:17 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element of data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;


void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur = *begin_list;
	t_list	*previous = NULL;

	while (cur)
	{
		if (cmp(cur->data, data_ref) == 0)
		{
			if (previous == NULL)
			{
				*begin_list = cur->next;
			}
			else
			{
				previous->next = cur->next;
			}
			t_list	*tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		else
		{
			previous = cur;
			cur = cur->next;
		}
	}
}



// The below functions are not required!!! It is just for testing purposes.

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	return (1);
}

t_list	*lst_new(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	*add_node_to_list(t_list *lst, void *data)
{
	t_list	*tmp = NULL;
	t_list	*new_node = NULL;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	tmp = lst->next;
	lst->next = new_node;
	new_node->data = data;
	new_node->next = tmp;
	return (new_node);
}

int	main(void)
{
	size_t	i;
	t_list	*lst;
	char *s[]={"remove", "a", "node", "from", "the", "linkded", "list", "****"};
	char ref[]="list";
	size_t size = sizeof(s) / sizeof(s[0]);

	i = size - 1;
	lst = lst_new(s[0]);
	while (i > 0)
	{
		add_node_to_list(lst, s[i]);
		i--;
	}
	// t_list *new_lst = ft_list_remove_if(&lst, ref, ft_strcmp);
	ft_list_remove_if(&lst, ref, ft_strcmp);
	while (lst)
	{
		printf("%s\t", (char *)lst->data);
		lst = lst->next;
	}
	printf("\n");
	return (0);
}
