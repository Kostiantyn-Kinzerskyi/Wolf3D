/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:26:59 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/17 17:27:01 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	textures(t_sdl *a, t_map *m)
{
	if (m->map[m->mx][m->my] == 1)
		m->t.tex2 = m->t.tex5;
	else if (m->map[m->mx][m->my] == 2)
		m->t.tex2 = m->t.tex5;
	else if (m->map[m->mx][m->my] == 3)
		m->t.tex2 = m->t.texside4;
	else if (m->map[m->mx][m->my] == 4)
		m->t.tex2 = m->t.texric;
	else
		m->t.tex2 = m->t.texside1;
	if (a->side == 0 && m->map[m->mx][m->my] > 1 && m->map[m->mx][m->my] < 3)
		m->t.tex2 = m->t.texside1;
	if (a->side == 1 && m->map[m->mx][m->my] > 1 && m->map[m->mx][m->my] < 3)
		m->t.tex2 = m->t.texside2;
	if (a->side == 2 && m->map[m->mx][m->my] > 1 && m->map[m->mx][m->my] < 3)
		m->t.tex2 = m->t.texside3;
	if (a->side == 3 && m->map[m->mx][m->my] > 1 && m->map[m->mx][m->my] < 3)
		m->t.tex2 = m->t.texside4;
}

void	draw_side(t_sdl *a, t_map *m)
{
	if (a->side == 0 || a->side == 2)
		m->t.wall_x = m->pos_y + a->p_walldis * a->rdir_y;
	else
		m->t.wall_x = m->pos_x + a->p_walldis * a->rdir_x;
	m->t.wall_x -= floor((m->t.wall_x));
	m->t.tex_x = (int)(m->t.wall_x * (double)T_WI);
	if ((a->side == 0 || a->side == 2) && a->rdir_x > 0)
		m->t.tex_x = T_WI - m->t.tex_x - 1;
	if ((a->side == 1 || a->side == 3) && a->rdir_y < 0)
		m->t.tex_x = T_WI - m->t.tex_x - 1;
}

void	draw_floor(t_sdl *a, t_map *m)
{
	draw_side(a, m);
	if ((a->side == 0 && a->rdir_x > 0) || (a->side == 2 && a->rdir_x > 0))
	{
		m->fl_xwall = m->mx;
		m->fl_ywall = m->my + m->t.wall_x;
	}
	else if ((a->side == 0 && a->rdir_x < 0) || (a->side == 2 && a->rdir_x < 0))
	{
		m->fl_xwall = m->mx + 1.0;
		m->fl_ywall = m->my + m->t.wall_x;
	}
	else if ((a->side == 1 && a->rdir_y > 0) || (a->side == 3 && a->rdir_y > 0))
	{
		m->fl_xwall = m->mx + m->t.wall_x;
		m->fl_ywall = m->my;
	}
	else
	{
		m->fl_xwall = m->mx + m->t.wall_x;
		m->fl_ywall = m->my + 1.0;
	}
	m->dist_wall = a->p_walldis;
	m->dist_pl = 0.0;
	textures(a, m);
}

void	wallcolor(t_sdl *a, t_map *m)
{
	if (a->side == 0)
		a->p_walldis = (m->mx - m->pos_x + (1 - a->st_x) / 2) / a->rdir_x;
	if (a->side == 1)
		a->p_walldis = (m->my - m->pos_y + (1 - a->st_y) / 2) / a->rdir_y;
	if (a->side == 2)
		a->p_walldis = (m->mx - m->pos_x + (1 - a->st_x) / 2) / a->rdir_x;
	if (a->side == 3)
		a->p_walldis = (m->my - m->pos_y + (1 - a->st_y) / 2) / a->rdir_y;
	m->line_h = (int)(S_HE / a->p_walldis);
	m->draw_st = -m->line_h / 2 + S_HE / 2;
	if (m->draw_st < 0)
		m->draw_st = 0;
	m->draw_en = m->line_h / 2 + S_HE / 2;
	if (m->draw_en >= S_HE)
		m->draw_en = S_HE - 1;
	draw_floor(a, m);
}
