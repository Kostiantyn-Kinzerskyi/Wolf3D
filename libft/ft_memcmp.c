/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:27:05 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/08 21:15:41 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*v1;
	const unsigned char	*v2;

	i = 0;
	v1 = s1;
	v2 = s2;
	while (i < n)
	{
		if (v1[i] > v2[i] || v1[i] < v2[i])
			return (v1[i] - v2[i]);
		i++;
	}
	return (0);
}
