/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:22:20 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/09 20:33:46 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int i;
	int w;

	i = 0;
	w = 0;
	if (!s || !c)
		return (0);
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			w++;
		i++;
	}
	if (s[i - 1] != c)
		w++;
	return (w);
}
