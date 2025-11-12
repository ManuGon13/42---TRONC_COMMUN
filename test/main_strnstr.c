/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:54:13 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:09:19 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	*big;
	const char	*little;
	size_t		len;

	big = "Hello world";
	little = "wor";
	len = 11;
	printf("%s\n", ft_strnstr(big, little, len));
	return (0);
}
