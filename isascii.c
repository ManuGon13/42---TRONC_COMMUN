/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:20:04 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 11:32:56 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '\0')
	{
		if (isascii(argv[1][i]))
			printf("%c est dans la table ascii\n", argv[1][i]);
		else
			printf("%c n'est pas dans la table ascii\n", argv[1][i]);
		i++;
	}
	return (0);
}*/
