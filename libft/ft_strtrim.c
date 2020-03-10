/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:27:27 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/15 16:13:48 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_out(char const *str)
{
	size_t		o;

	o = 0;
	if (!str)
		return (0);
	while (str[o + 1] != '\0')
		o++;
	while (str[o] == ' ' || str[o] == '\n' || str[o] == '\t')
		o--;
	o = o + 1;
	if (o == 0)
		return (1);
	return (o);
}

static size_t	ft_in(char const *str)
{
	size_t		g;

	g = 0;
	if (!str)
		return (0);
	while (str[g] == ' ' || str[g] == '\n' || str[g] == '\t')
		g++;
	if (g == ft_strlen(str))
		return (1);
	return (g);
}

char			*ft_strtrim(char const *s)
{
	char		*q;
	int			i;
	size_t		m;
	size_t		n;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		q = "";
		return (q);
	}
	n = ft_in(s);
	m = ft_out(s);
	q = (char*)malloc(sizeof(char) * (m - n + 1));
	if (!q)
		return (0);
	while (n < m)
		q[i++] = s[n++];
	q[i] = '\0';
	return (q);
}
