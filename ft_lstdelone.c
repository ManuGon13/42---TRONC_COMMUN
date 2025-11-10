/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:51:20 by egonin            #+#    #+#             */
/*   Updated: 2025/11/10 11:10:29 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = malloc(20 * sizeof(char));
	if (!node->content)
	{
		free(node);
		return (1);
	}
	node->next = NULL;

	printf("avant suppr : node = %p, content = %p\n", node, node->content);
	ft_lstdelone(node, del);
	printf("apres suppr : maillon suppr \n");
	return (0);
}
