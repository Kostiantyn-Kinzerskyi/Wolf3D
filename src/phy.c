/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:28:41 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/19 17:28:42 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	read2(char *str, t_map *a, int i, int j)
{
	if (!ft_strcmp(str, "P"))
		check_player(a, j, i, 0);
	if (ft_strcmp(str, "0") && ft_strcmp(str, "1") &&
		ft_strcmp(str, "2") && ft_strcmp(str, "3") &&
		ft_strcmp(str, "4") && ft_strcmp(str, "P"))
		merror();
}

void	torch(t_sdl *a, t_map *m)
{
	if (a->torch == 0)
	{
		m->shfact = 1.5;
		a->torch = 1;
	}
	else
	{
		m->shfact = 3.5;
		a->torch = 0;
	}
}

void	phy(t_sdl *a, t_map *m)
{
	if (m->i > 0)
	{
		if (m->map[(int)(m->pos_x + a->dir_x *
			a->speed * 6)][(int)(m->pos_y)] == 0)
			m->pos_x += a->dir_x * a->speed;
		if (m->map[(int)(m->pos_x)][(int)(m->pos_y +
			a->dir_y * a->speed * 6)] == 0)
			m->pos_y += a->dir_y * a->speed;
		m->i--;
	}
	if (m->ri > 0)
	{
		if (m->map[(int)(m->pos_x - a->dir_x *
			a->speed * 6)][(int)(m->pos_y)] == 0)
			m->pos_x -= a->dir_x * a->speed;
		if (m->map[(int)(m->pos_x)][(int)(m->pos_y -
			a->dir_y * a->speed * 6)] == 0)
			m->pos_y -= a->dir_y * a->speed;
		m->ri--;
	}
}
