/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 09:34:31 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/09 20:35:26 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *restrict dst, const void *restrict src, \
				int c, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		if (s[i] == (char)c)
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
