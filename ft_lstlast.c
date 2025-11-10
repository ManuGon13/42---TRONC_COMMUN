/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:50:36 by egonin            #+#    #+#             */
/*   Updated: 2025/11/10 10:28:23 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

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

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	c = ft_lstnew("C");
	a->next = b;
	b->next = c;
	last = ft_lstlast(a);
	if (last)
		printf("dernier element : %s\n", (char *)last-> content);
	else
		printf("liste vide.\n");
	return (0);
}
