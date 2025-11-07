/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:51:15 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 11:37:01 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}

/*int	main(int argc, char **argv)
{
	const char	*str = argv[1];
	char		c;
	char		*result;

	c = argv[2][0];
	*result = strrchr(str, c);
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
}*/
