/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:10:52 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/08 21:18:28 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	if (s != d)
	{
		if (d > s)
			while (len > 0)
			{
				d[len - 1] = s[len - 1];
				len--;
			}
		else
			while (i < len)
			{
				d[i] = s[i];
				i++;
			}
		return (d);
	}
	else
		return (0);
}
