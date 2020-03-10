/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:08:22 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/03 16:08:26 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_mas(char **mas)
{
	int		i;

	i = 0;
	while (mas[i])
		free(mas[i++]);
	free(mas);
}

void		check_player(t_map *a, int j, int i, int r)
{
	if (r == 0)
	{
		a->pos_x = j + 0.5;
		a->pos_y = i + 0.5;
		a->check_p++;
	}
	if (r == 1)
		if (i > 0)
			if (a->map[j][i - 1] == 0)
				a->check_p = 2;
	if (r == 2)
		if (a->map[j][i] == 0)
			a->check_p = 2;
}

void		read_map(char *filename, t_map *a, int j, int i)
{
	int		fd;
	char	*line;
	char	**mas;

	a->map = (int **)malloc(sizeof(int *) * a->map_h);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		mas = ft_strsplit(line, ' ');
		free(line);
		i = -1;
		a->map[j] = (int *)malloc(sizeof(int) * a->map_w);
		while (mas[++i])
		{
			read2(mas[i], a, i, j);
			a->map[j][i] = ft_atoi(mas[i]);
			if (i == 0)
				check_player(a, j, i, 2);
		}
		check_player(a, j, i, 1);
		free_mas(mas);
		j++;
	}
	free(line);
}

int			count_map(char *filename, t_map *a)
{
	int		fd;
	char	*line;
	char	**mas;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (a->map_h > 400)
			break ;
		a->map_h++;
		mas = ft_strsplit(line, ' ');
		free(line);
		if (!valid_string(a, mas))
		{
			free_mas(mas);
			return (0);
		}
		free_mas(mas);
	}
	free(line);
	if (a->map_h > 400)
		return (0);
	return (1);
}

int			ft_read(char *filename, t_map *a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	a->check_p = 0;
	if (!check_file(filename))
		return (0);
	a->map_w = 0;
	a->map_h = 0;
	if (!count_map(filename, a))
		return (0);
	read_map(filename, a, 0, 0);
	if (a->check_p != 1)
		return (0);
	if (!check_wall(a))
		return (0);
	return (1);
}
