/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:20:04 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:04:54 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int		i;
	char	str[];

	str[] = {'A', ' ', '\n', '\t', 127, '!', 0};
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]))
			printf("%c est un printable\n", str[i]);
		else
			printf("%c n'est pas printable\n", str[i]);
		i++;
	}
	return (0);
}
