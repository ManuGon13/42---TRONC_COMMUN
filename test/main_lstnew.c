/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:44:11 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:11:57 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Bonjour");
	if (node)
	{
		printf("Contenu : %s\n", (char *)node->content);
		printf("Next : %p\n", node->next);
	}
	return (0);
}
