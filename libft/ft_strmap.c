/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:11:49 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/08 21:50:16 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*q;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	q = (char*)malloc(sizeof(char) * (i + 1));
	if (!q)
		return (NULL);
	i = 0;
	while (s[i])
	{
		q[i] = f(s[i]);
		i++;
	}
	q[i] = '\0';
	return (q);
}
