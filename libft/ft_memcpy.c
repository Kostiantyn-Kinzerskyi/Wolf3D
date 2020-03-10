/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:09:19 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/08 21:17:20 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*q;
	char	*d;

	i = 0;
	q = (char*)dst;
	d = (char*)src;
	while (i < n)
	{
		q[i] = d[i];
		i++;
	}
	return (q);
}
