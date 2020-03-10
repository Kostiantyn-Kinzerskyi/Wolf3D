/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:56:59 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/17 17:53:08 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H
# define S_WI 1600
# define S_HE 900
# define T_WI 64
# define T_HE 64
# include <SDL2/SDL.h>
# include "get_next_line.h"
# include <SDL_image.h>

typedef struct		s_tex
{
	SDL_Surface		*textop;
	SDL_Surface		*tex2;
	SDL_Surface		*texfl;
	SDL_Surface		*texric;
	SDL_Surface		*texside1;
	SDL_Surface		*texside2;
	SDL_Surface		*texside3;
	SDL_Surface		*texside4;
	SDL_Surface		*texaxe;
	SDL_Surface		*tex5;
	SDL_Rect		srcrect;
	SDL_Rect		dstrect;
	int				tex_x;
	int				tex_y;
	int				fl_tex_x;
	int				fl_tex_y;
	int				d;
	double			wall_x;
	double			weight;
	double			cur_fl_x;
	double			cur_fl_y;
}					t_tex;

typedef struct		s_map
{
	unsigned char	*pix_t;
	unsigned char	*pix_t2;
	unsigned char	*pix;
	double			fl_xwall;
	double			fl_ywall;
	double			dist_wall;
	double			dist_pl;
	double			cur_dist;
	double			sh;
	double			shfact;
	double			shdst;
	t_tex			t;
	int				s_up;
	int				s_down;
	int				s_right;
	int				s_left;
	int				s_shift;
	int				map_w;
	int				map_h;
	int				mx;
	int				my;
	int				col;
	int				draw_st;
	int				draw_en;
	int				check_p;
	int				**map;
	int				x;
	int				line_h;
	int				kshade;
	int				i;
	int				ri;
	double			pos_x;
	double			pos_y;
}					t_map;

typedef struct		s_sdl
{
	double			speed;
	double			r_speed;
	double			dir_x;
	double			dir_y;
	double			pl_x;
	double			pl_y;
	double			cam_x;
	double			odir_x;
	double			opl_x;
	double			rdir_x;
	double			rdir_y;
	double			sdist_x;
	double			sdist_y;
	double			d_dist_x;
	double			d_dist_y;
	double			p_walldis;
	int				torch;
	int				st_x;
	int				st_y;
	int				hit;
	int				side;
}					t_sdl;

int					main(int argc, char **argv);
int					ft_read(char *filename, t_map *a);
int					valid_string(t_map *a, char **mas);
int					check_file(char *filename);
void				draw(SDL_Surface *surface, int i, t_map *m, t_sdl *a);
void				init(t_map *m, t_sdl *a);
void				wallcolor(t_sdl *a, t_map *m);
int					check_wall(t_map *a);
void				write_map(t_map *a);
void				keys(SDL_Event *e, t_sdl *a, t_map *m);
void				ray(SDL_Surface *surface, t_sdl *a, t_map *m);
void				open_file(int argc, char *filename, t_map *m);
void				init_texture(t_map *m);
void				phy(t_sdl *a, t_map *m);
void				torch(t_sdl *a, t_map *m);
void				merror(void);
void				read2(char *str, t_map *a, int i, int j);
void				check_player(t_map *a, int j, int i, int r);
#endif
