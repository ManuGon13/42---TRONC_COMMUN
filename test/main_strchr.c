/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:51:15 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:07:54 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	const char	*str;
	char		*c;
	char		*result;

	str = argv[1];
	c = argv[2][0];
	result = ft_strchr(str, c);
	if (argc != 3)
	{
		printf("Il manque un argument");
		return (0);
	}
	if (result)
		printf("Caractere '%c' trouve a partir de: \"%s\"\n", c, result);
	else
		printf("Caractere '%c' non trouve dans: \"%s\"\n", c, str);
	return (0);
}
