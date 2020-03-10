/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:13:57 by kkinzers          #+#    #+#             */
/*   Updated: 2018/12/03 18:08:21 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*q;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(q = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
		q[i++] = s[start++];
	q[i] = '\0';
	return (q);
}
