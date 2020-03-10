/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:54:27 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/05 21:07:11 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(int argc, char **argv)
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Event	e;
	t_sdl		a;
	t_map		m;

	init_texture(&m);
	open_file(argc, argv[1], &m);
	init(&m, &a);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("42", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, S_WI, S_HE, SDL_WINDOW_SHOWN);
	if (window == NULL)
		return (1);
	surface = SDL_GetWindowSurface(window);
	while (1)
	{
		ray(surface, &a, &m);
		keys(&e, &a, &m);
		if (a.torch == 1)
			SDL_BlitSurface(m.t.texaxe, &m.t.srcrect, surface, &m.t.dstrect);
		SDL_UpdateWindowSurface(window);
	}
}
