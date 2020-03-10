/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:08:40 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/06 19:08:41 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_texture(t_map *m)
{
	if (!(m->t.textop = IMG_Load("textures/mud.png")))
		exit(0);
	if (!(m->t.texfl = IMG_Load("textures/floor.png")))
		exit(0);
	if (!(m->t.texric = IMG_Load("textures/r.png")))
		exit(0);
	if (!(m->t.texside1 = IMG_Load("textures/wood.png")))
		exit(0);
	if (!(m->t.texside2 = IMG_Load("textures/mud.png")))
		exit(0);
	if (!(m->t.texside3 = IMG_Load("textures/mine.png")))
		exit(0);
	if (!(m->t.texside4 = IMG_Load("textures/gorg.png")))
		exit(0);
	if (!(m->t.tex5 = IMG_Load("textures/wall.png")))
		exit(0);
	if (!(m->t.texaxe = IMG_Load("textures/torch.png")))
		exit(0);
}

void	init2(t_map *m)
{
	m->t.srcrect.x = 0;
	m->t.srcrect.y = 0;
	m->t.srcrect.w = 513;
	m->t.srcrect.h = 513;
	m->t.dstrect.x = S_WI / 2;
	m->t.dstrect.y = S_HE - 513;
	m->t.dstrect.w = 0;
	m->t.dstrect.h = 0;
}

void	init(t_map *m, t_sdl *a)
{
	a->side = 0;
	m->s_up = 0;
	m->s_down = 0;
	m->s_left = 0;
	m->s_right = 0;
	a->dir_x = -1;
	a->dir_y = 0;
	a->pl_x = 0;
	a->pl_y = 0.66;
	a->speed = 0.035;
	a->r_speed = 0.035;
	m->shdst = 0.6;
	m->shfact = 3.5;
	m->sh = 1;
	m->kshade = 0;
	m->i = 0;
	m->ri = 0;
	a->torch = 0;
	init2(m);
}
