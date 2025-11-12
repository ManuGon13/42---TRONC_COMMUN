/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:23:14 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:47:31 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*s;
	char	*res;

	s = "***Allez l'OM*****";
	res = ft_strtrim(s, "*");
	printf("avant:%s\n", s);
	printf("apres:%s\n", res);
	free(res);
	return (0);
}
