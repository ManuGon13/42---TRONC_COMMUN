/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:51:39 by egonin            #+#    #+#             */
/*   Updated: 2025/11/07 20:03:45 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdlib.h>
#include  <stdio.h>

static int  ft_intlen(int n)
{
  int len;

  if (n <= 0)
    len = 1;
  else
    len = 0;
  while (n != 0)
  {
    n /= 10;
    len++;
  }
  return (len);
}

char  *ft_itoa(int n)
{
  char  *str;
  long  nb;
  int   len;

  nb = n;
  len = ft_intlen(n);
  str = malloc(len + 1);
  if (!str)
    return (NULL);
  str[len] = '\0';
  if (nb == 0)
    str[0] = '0';
  if (nb < 0)
  {
    str[0] = '-';
    nb = -nb;
  }
  while (nb > 0)
  {
    len = len - 1;
    str[len] = (nb % 10) + '0';
    nb = nb / 10;
  }
  return (str);
}

int main(void)
{
  char  *str;

  str = ft_itoa(12345);
  printf("ft_itoa(12345 = %s\n", str);
  free(str);
  return (0);
}
