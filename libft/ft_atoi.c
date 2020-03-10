/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:44:02 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/15 15:57:03 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	t;
	int					g;

	i = 0;
	t = 0;
	g = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		g = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		t = (t * 10) + (str[i] - 48);
		if (t >= 9223372036854775807 && g == 1)
			return (-1);
		else if (t > 9223372036854775807 && g == -1)
			return (0);
		i++;
	}
	return (t * g);
}
