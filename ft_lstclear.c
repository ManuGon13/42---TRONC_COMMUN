/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:28:10 by egonin            #+#    #+#             */
/*   Updated: 2025/11/10 13:01:46 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	del(void *content)
{
	free(content);
}

char	*strdup(const char *s)
{
	int	i;
	char	*copy;

	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

t_list  *list(char *s)
{
	t_list  *n;

	n = malloc(sizeof(*n));
	n->content = strdup(s);
	n->next = NULL;
	return (n);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = list("A");
	b = list("B");
	c = list("C");
	a->next = b;
	b->next = c;
	ft_lstclear(&a, del);
	printf("a = %p\n", (void *)a);
	return (0);
}
