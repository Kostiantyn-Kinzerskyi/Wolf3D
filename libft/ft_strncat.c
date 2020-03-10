/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:29:09 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/09 20:39:57 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (s1[s])
		s++;
	while (s2[i] && i < n)
	{
		s1[s] = s2[i];
		i++;
		s++;
	}
	s1[s] = '\0';
	return (s1);
}
