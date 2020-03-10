/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:03:08 by kkinzers          #+#    #+#             */
/*   Updated: 2018/12/06 18:02:58 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*q;
	int		l;
	int		i;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	q = (char*)malloc(sizeof(char) * (l + 1));
	if (!q)
		return (NULL);
	while (s1[i])
	{
		q[i] = s1[i];
		i++;
	}
	l = 0;
	while (s2[l])
		q[i++] = s2[l++];
	q[i] = '\0';
	return (q);
}
