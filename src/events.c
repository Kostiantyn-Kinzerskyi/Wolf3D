/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:03:29 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/06 18:03:31 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sup_events2(t_sdl *a, int i)
{
	if (i == 3)
	{
		a->odir_x = a->dir_x;
		a->dir_x = a->dir_x * cos(-a->r_speed) - a->dir_y * sin(-a->r_speed);
		a->dir_y = a->odir_x * sin(-a->r_speed) + a->dir_y * cos(-a->r_speed);
		a->opl_x = a->pl_x;
		a->pl_x = a->pl_x * cos(-a->r_speed) - a->pl_y * sin(-a->r_speed);
		a->pl_y = a->opl_x * sin(-a->r_speed) + a->pl_y * cos(-a->r_speed);
	}
	if (i == 4)
	{
		a->odir_x = a->dir_x;
		a->dir_x = a->dir_x * cos(a->r_speed) - a->dir_y * sin(a->r_speed);
		a->dir_y = a->odir_x * sin(a->r_speed) + a->dir_y * cos(a->r_speed);
		a->opl_x = a->pl_x;
		a->pl_x = a->pl_x * cos(a->r_speed) - a->pl_y * sin(a->r_speed);
		a->pl_y = a->opl_x * sin(a->r_speed) + a->pl_y * cos(a->r_speed);
	}
}

void	sup_events(t_sdl *a, t_map *m, int i)
{
	if (i == 1)
	{
		if (m->map[(int)(m->pos_x + a->dir_x *
			a->speed * 6)][(int)(m->pos_y)] == 0)
			m->pos_x += a->dir_x * a->speed;
		if (m->map[(int)(m->pos_x)][(int)(m->pos_y +
			a->dir_y * a->speed * 6)] == 0)
			m->pos_y += a->dir_y * a->speed;
		if (a->speed == 0.6)
			m->i = 20;
		m->i = 10;
	}
	if (i == 2)
	{
		if (m->map[(int)(m->pos_x - a->dir_x *
			a->speed * 6)][(int)(m->pos_y)] == 0)
			m->pos_x -= a->dir_x * a->speed;
		if (m->map[(int)(m->pos_x)][(int)(m->pos_y -
			a->dir_y * a->speed * 6)] == 0)
			m->pos_y -= a->dir_y * a->speed;
		m->ri = 10;
	}
	sup_events2(a, i);
}

void	events2(SDL_Event *e, t_sdl *a, t_map *m)
{
	if (e->type == SDL_KEYUP)
	{
		if (e->key.keysym.sym == SDLK_UP)
			m->s_up = 0;
		if (e->key.keysym.sym == SDLK_DOWN)
			m->s_down = 0;
		if (e->key.keysym.sym == SDLK_RIGHT)
			m->s_right = 0;
		if (e->key.keysym.sym == SDLK_LEFT)
			m->s_left = 0;
		if (e->key.keysym.sym == SDLK_LSHIFT)
			a->speed = 0.035;
		if (e->key.keysym.sym == SDLK_LCTRL)
		{
			if (m->kshade == 1)
			{
				m->sh = 1;
				m->kshade = 0;
			}
			else
				m->kshade = 1;
		}
	}
	if (e->type == SDL_QUIT)
		exit(0);
}

void	events(SDL_Event *e, t_sdl *a, t_map *m)
{
	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_KEYDOWN)
		{
			if (e->key.keysym.sym == SDLK_UP)
				m->s_up = 1;
			if (e->key.keysym.sym == SDLK_DOWN)
				m->s_down = 1;
			if (e->key.keysym.sym == SDLK_RIGHT)
				m->s_right = 1;
			if (e->key.keysym.sym == SDLK_LEFT)
				m->s_left = 1;
			if (e->key.keysym.sym == SDLK_LSHIFT)
				a->speed = 0.06;
			if (e->key.keysym.sym == SDLK_LALT)
				torch(a, m);
			if (e->key.keysym.sym == SDLK_ESCAPE)
				exit(0);
		}
		events2(e, a, m);
	}
}

void	keys(SDL_Event *e, t_sdl *a, t_map *m)
{
	if (m->s_up == 1)
		sup_events(a, m, 1);
	if (m->s_down == 1)
		sup_events(a, m, 2);
	if (m->s_right == 1)
		sup_events(a, m, 3);
	if (m->s_left == 1)
		sup_events(a, m, 4);
	events(e, a, m);
	phy(a, m);
}
