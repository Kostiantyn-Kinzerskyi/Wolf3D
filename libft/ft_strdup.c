/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:20:59 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/09 16:48:35 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		q;
	char	*w;

	q = 0;
	i = 0;
	while (s1[q])
		q++;
	w = (char*)malloc(sizeof(char) * (q + 1));
	if (!w)
		return (0);
	while (s1[i])
	{
		w[i] = s1[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}
