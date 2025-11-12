/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:43 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:08:45 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*str;
	char	*ptr;

	str[] = "Bonjour";
	*ptr = ft_memchr(str, 'j', 7);
	if (ptr)
		printf("Trouve : %s\n", ptr);
	else
		printf("Non trouve\n");
	return (0);
}
