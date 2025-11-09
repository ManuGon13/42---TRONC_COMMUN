/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:25:00 by egonin            #+#    #+#             */
/*   Updated: 2025/11/08 17:40:57 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    last = *lst;
    while (last->next)
        last = last->next;
    last->next = new;

}

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("B");
	new = ft_lstnew("A");

	ft_lstadd_fback(&lst, new);
	printf("1er maillon : %s\n", (char *)lst->content);
	printf("suivant : %s\n", (char *)lst->next->content);
	return (0);
}