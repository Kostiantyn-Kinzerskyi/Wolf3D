/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 23:10:43 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/09 20:38:48 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	q;
	size_t	m;
	size_t	k;

	k = dstsize;
	i = 0;
	q = 0;
	while (dst[q] && q < dstsize)
		q++;
	m = q;
	while (src[q - m] && m + 1 < k)
	{
		dst[q] = src[q - m];
		q++;
		k--;
	}
	if (m < dstsize)
		dst[q] = '\0';
	return (ft_strlen(src) + m);
}
