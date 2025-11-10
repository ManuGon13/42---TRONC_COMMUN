/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:21:27 by egonin            #+#    #+#             */
/*   Updated: 2025/11/10 12:14:50 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*list(char *s)
{
	t_list	*n;

	n = malloc(sizeof(*n));
	n->content = s;
	n->next = NULL;
	return (n);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = list("B");
	new = list("A");
	ft_lstadd_front(&lst, new);
	printf("1er maillon : %s\n", (char *)lst->content);
	printf("suivant : %s\n", (char *)lst->next->content);
	return (0);
}
