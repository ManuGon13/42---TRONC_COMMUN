/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:21:42 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:03:52 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '\0')
	{
		if (ft_isalpha(argv[1][i]))
			printf("%c est une lettre\n", argv[1][i]);
		else
			printf("%c n'est pas une lettre\n", argv[1][i]);
		i++;
	}
	return (0);
}
