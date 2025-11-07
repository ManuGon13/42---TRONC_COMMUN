/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:20:04 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 11:33:36 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	int		i;
	char	str[];

	str[] = {'A', ' ', '\n', '\t', 127, '!', 0};
	i = 0;
	while (str[i] != '\0')
	{
		if (isprint(str[i]))
			printf("%c est un printable\n", str[i]);
		else
			printf("%c n'est pas printable\n", str[i]);
		i++;
	}
	return (0);
}*/
