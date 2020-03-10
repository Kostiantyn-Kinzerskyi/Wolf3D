/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:39:12 by kkinzers          #+#    #+#             */
/*   Updated: 2018/12/11 19:14:06 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_word(char const *s, char c, int a)
{
	int		i;
	char	*str;

	if (!s || !c)
		return (NULL);
	i = a;
	while (s[i] != c && s[i])
		i++;
	i = i - a;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[a] != c && s[a])
		str[i++] = s[a++];
	str[i] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w;
	char	**str;

	i = 0;
	w = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			str[w] = ft_word(s, c, i);
		w++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	str[w] = 0;
	return (str);
}
