/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:20:51 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:14:50 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*lst;
	char	*s;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (1);
	lst->content = malloc(20 * sizeof(char));
	if (!lst->content)
	{
		free(lst);
		return (1);
	}
	s = (char *)lst->content;
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
	ft_lstiter(lst, f);
	printf("maillon modif:%s\n", (char *)lst->content);
	free(lst->content);
	free(lst);
	return (0);
}
