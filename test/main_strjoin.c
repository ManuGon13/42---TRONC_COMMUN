/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:33:53 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:47:18 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char const	*a;
	char const	*b;

	a = "Allez";
	b = " l'OM";
	printf("%s\n", ft_strjoin(a, b));
	return (0);
}
