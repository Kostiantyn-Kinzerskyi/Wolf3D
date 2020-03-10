/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:10:50 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/06 18:11:02 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_second(SDL_Surface *surface, int i, int b, t_map *m)
{
	m->pix = surface->pixels;
	while (++i < S_HE)
	{
		m->cur_dist = S_HE / (2.0 * i - S_HE);
		if (m->kshade == 1)
			m->sh = m->cur_dist * m->shfact;
		m->t.weight = (m->cur_dist - m->dist_pl) /
		(m->dist_wall - m->dist_pl);
		m->t.cur_fl_x = m->t.weight * m->fl_xwall +
		(1.0 - m->t.weight) * m->pos_x;
		m->t.cur_fl_y = m->t.weight * m->fl_ywall +
		(1.0 - m->t.weight) * m->pos_y;
		m->t.fl_tex_x = (int)(m->t.cur_fl_x * T_WI) % T_WI;
		m->t.fl_tex_y = (int)(m->t.cur_fl_y * T_HE) % T_HE;
		b = m->t.fl_tex_y * m->t.texfl->w + m->t.fl_tex_x;
		m->pix[4 * (i * surface->w + m->x)] = m->pix_t[4 * b] / m->sh;
		m->pix[4 * (i * surface->w + m->x) + 1] = m->pix_t[4 * b + 1] / m->sh;
		m->pix[4 * (i * surface->w + m->x) + 2] = m->pix_t[4 * b + 2] / m->sh;
		b = m->t.fl_tex_y * m->t.textop->w + m->t.fl_tex_x;
		m->pix[4 * ((S_HE - i) * surface->w + m->x)] = m->pix_t2[4 * b] / m->sh;
		m->pix[4 * ((S_HE - i) * surface->w + m->x) + 1] =
		m->pix_t2[4 * b + 1] / m->sh;
		m->pix[4 * ((S_HE - i) * surface->w + m->x) + 2] =
		m->pix_t2[4 * b + 2] / m->sh;
	}
}

void	draw(SDL_Surface *surface, int i, t_map *m, t_sdl *a)
{
	m->pix_t = m->t.tex2->pixels;
	m->pix = surface->pixels;
	while (m->draw_st <= m->draw_en)
	{
		if (m->kshade == 1)
		{
			m->sh = a->p_walldis * m->shfact;
			if (a->p_walldis < m->shdst)
				m->sh = m->shdst * m->shfact;
		}
		m->t.d = m->draw_st * 256 - S_HE * 128 + m->line_h * 128;
		m->t.tex_y = ((m->t.d * T_HE) / m->line_h) / 256;
		m->pix[4 * (m->draw_st * surface->w + m->x)] =
		m->pix_t[4 * (m->t.tex_y * m->t.tex2->w + m->t.tex_x)] / m->sh;
		m->pix[4 * (m->draw_st * surface->w + m->x) + 1] =
		m->pix_t[4 * (m->t.tex_y * m->t.tex2->w + m->t.tex_x) + 1] / m->sh;
		m->pix[4 * (m->draw_st * surface->w + m->x) + 2] =
		m->pix_t[4 * (m->t.tex_y * m->t.tex2->w + m->t.tex_x) + 2] / m->sh;
		m->draw_st++;
	}
	i = m->draw_en - 1;
	m->pix_t = m->t.texfl->pixels;
	m->pix_t2 = m->t.textop->pixels;
	draw_second(surface, i, 0, m);
}

void	hit(t_sdl *a, t_map *m)
{
	a->hit = 0;
	while (a->hit == 0)
	{
		if (a->sdist_x < a->sdist_y)
		{
			a->sdist_x += a->d_dist_x;
			m->mx += a->st_x;
			if (a->rdir_x > 0)
				a->side = 0;
			else
				a->side = 2;
		}
		else if (a->sdist_x > a->sdist_y)
		{
			a->sdist_y += a->d_dist_y;
			m->my += a->st_y;
			if (a->rdir_y > 0)
				a->side = 1;
			else
				a->side = 3;
		}
		if (m->map[m->mx][m->my] > 0)
			a->hit = 1;
	}
}

void	dir(t_sdl *a, t_map *m)
{
	m->mx = (int)m->pos_x;
	m->my = (int)m->pos_y;
	a->d_dist_x = fabs(1 / a->rdir_x);
	a->d_dist_y = fabs(1 / a->rdir_y);
	if (a->rdir_x < 0)
	{
		a->st_x = -1;
		a->sdist_x = (m->pos_x - m->mx) * a->d_dist_x;
	}
	else
	{
		a->st_x = 1;
		a->sdist_x = (m->mx + 1.0 - m->pos_x) * a->d_dist_x;
	}
	if (a->rdir_y < 0)
	{
		a->st_y = -1;
		a->sdist_y = (m->pos_y - m->my) * a->d_dist_y;
	}
	else
	{
		a->st_y = 1;
		a->sdist_y = (m->my + 1.0 - m->pos_y) * a->d_dist_y;
	}
}

void	ray(SDL_Surface *surface, t_sdl *a, t_map *m)
{
	SDL_FillRect(surface, NULL, 0x000000);
	m->x = -1;
	while (++m->x < S_WI)
	{
		a->cam_x = 2 * m->x / (double)(S_WI) - 1;
		a->rdir_x = a->dir_x + a->pl_x * a->cam_x;
		a->rdir_y = a->dir_y + a->pl_y * a->cam_x;
		dir(a, m);
		hit(a, m);
		wallcolor(a, m);
		draw(surface, -1, m, a);
	}
}
