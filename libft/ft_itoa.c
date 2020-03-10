/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:33:23 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/09 19:28:23 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev(char *s)
{
	int		i;
	int		q;
	int		m;
	char	a;

	if (!s)
		return (NULL);
	i = 0;
	q = 0;
	m = 0;
	while (s[q++])
		i = q - 1;
	if (s[m] == '-')
	{
		q--;
		m++;
	}
	q = q / 2;
	while (q-- > 0)
	{
		a = s[m++];
		s[m - 1] = s[i--];
		s[i + 1] = a;
	}
	return (s);
}

static int	ft_countint(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0 || n < -2147483648 || n > 2147483647)
		return (1);
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	if (n > 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*b;

	i = 0;
	if (!(b = (char*)malloc(sizeof(char) * (ft_countint(n) + 1))))
		return (NULL);
	if (n < 0 && n >= -2147483648)
		b[i++] = '-';
	if (n == -2147483648)
		b[i++] = '8';
	if (n == -2147483648)
		n = n / 10;
	if (n < 0)
		n *= -1;
	while (n / 10 > 0 && n <= 2147483647)
	{
		b[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (n > 0)
		b[i++] = (n % 10) + 48;
	if (n == 0)
		b[i++] = '0';
	b[i] = '\0';
	return (ft_rev(b));
}
