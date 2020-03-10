/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:15:18 by kkinzers          #+#    #+#             */
/*   Updated: 2018/10/29 20:32:23 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t g;
	size_t m;

	i = 0;
	g = 0;
	m = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] && ft_strlen(haystack) >= ft_strlen(needle) && i < len)
	{
		m = i;
		while (haystack[m] == needle[g] && m < len)
		{
			if (haystack[m] == '\0' && needle[g] == '\0')
				return ((char*)&haystack[m - g]);
			m++;
			g++;
		}
		if (needle[g] == '\0')
			return ((char*)&haystack[m - g]);
		g = 0;
		i++;
	}
	return (0);
}
