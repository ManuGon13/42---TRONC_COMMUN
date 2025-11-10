/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:44:32 by egonin            #+#    #+#             */
/*   Updated: 2025/11/10 19:41:59 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

 t_list  *ft_lstnew(void *content)
 {
	t_list  *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next  = NULL;
	return (new);
 }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

void	del(void *content)
{
	free(content);
}

void    f(void  *content)
{
	char    *str = (char *)content;
	int     i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

int     main(void)
{
	t_list  *lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (1);
	lst->content = malloc(20 * sizeof(char));
	if (!lst->content)
	{
		free(lst);
		return (1);
	}
	char *s = (char *)lst->content;
	s[0] = 'a';
	s[1] = 'l';
	s[2] = 'l';
	s[3] = 'e';
	s[4] = 'z';
	s[5] = ' ';
	s[6] = 'l';
	s[7] = '\'';
	s[8] = 'o';
	s[9] = 'm';
	s[10] = '\0';
	lst->next = NULL;
	ft_lstmap(lst, *f, del);
	printf("maillon modif:%s\n", (char *)lst->content);
	free(lst->content);
	free(lst);
	return (0);
}
