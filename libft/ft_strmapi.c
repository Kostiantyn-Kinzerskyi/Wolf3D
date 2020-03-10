/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:33:57 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/08 21:51:09 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*q;
	unsigned int	i;

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
		q[i] = f(i, s[i]);
		i++;
	}
	q[i] = '\0';
	return (q);
}
