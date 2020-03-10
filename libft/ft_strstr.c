/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:32:45 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/08 22:05:45 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t g;
	size_t m;

	i = 0;
	g = 0;
	m = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] && ft_strlen(haystack) >= ft_strlen(needle))
	{
		m = i;
		while (haystack[m] == needle[g])
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
