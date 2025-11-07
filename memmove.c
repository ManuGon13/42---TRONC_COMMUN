/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:06:41 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 11:35:02 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n > 0)
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	else if (d > s)
	{
		d = d + n;
		s = s + n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}

/*int	main(void)
{
	char	*str;

	str[] = "abcdef";
	memmove(str + 2, str, 4);
	printf("%s\n", str);
	return (0);
}*/
