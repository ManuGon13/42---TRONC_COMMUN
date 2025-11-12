/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:48:41 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:47:44 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char		**result;
	char const	*str;
	int			i;

	i = 0;
	str = "Hello, 42, Paris";
	result = ft_split(str, ',');
	while (result[i])
	{
		printf("[%s]\n", result[i]);
		i++;
	}
	return (0);
}
