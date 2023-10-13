/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:17:56 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/13 15:46:49 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
--------------------------------------------------------------------------------
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str);

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr = begin_list;

	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}




// The below functions are not required!!! It is just for testing purposes.

void	ft_putstr(char *str)
{
	int	len = 0;

	while (str[len])
	{
		len++;
	}
	write (1, str, len);
	write (1, " ", 1);
}

t_list	*ft_lstnew(void *data)
{
	t_list *new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

t_list	*ft_add_node(t_list *begin_list, void *data)
{
	t_list	*new_node = NULL;
	t_list	*tmp = NULL;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	tmp = begin_list->next;
	begin_list->next = new_node;
	new_node->data = data;
	new_node->next = tmp;
	return (new_node);
}

int	main(void)
{
	int	i = 0;
	t_list *begin_list = NULL;

	char *s[]={"hey", "this", "is", "a", "linked", "list", "test"};
	int	arr_size = sizeof(s) / sizeof(s[0]);
	i = arr_size - 1;

	begin_list = ft_lstnew((void *)s[0]);
	while (i > 0)
	{
		ft_add_node(begin_list, (void *)s[i]);
		i--;
	}
	ft_list_foreach(begin_list, (void *)ft_putstr);
	write(1, "\n", 1);
	return (0);
}
