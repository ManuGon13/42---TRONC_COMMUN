/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:50:36 by egonin            #+#    #+#             */
/*   Updated: 2025/11/10 17:46:53 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*last;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	if (!a || !b || !c)
		return (1);
	a->content = malloc(2 * sizeof(char));
	b->content = malloc(2 * sizeof(char));
	c->content = malloc(2 * sizeof(char));
	if (!a->content)
	{
		free(a);
		return (1);
	}
	if (!b->content)
	{
		free(b);
		return (1);
	}
	if (!c->content)
	{
		free(c);
		return (1);
	}
	a->content = "A";
	b->content = "B";
	c->content = "C";
	a->next = b;
	b->next = c;
	last = ft_lstlast(a);
	if (last)
		printf("dernier element : %s\n", (char *)last-> content);
	else
		printf("liste vide.\n");
	return (0);
}
