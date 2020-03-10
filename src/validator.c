/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:05:01 by kkinzers          #+#    #+#             */
/*   Updated: 2019/07/03 16:05:03 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		merror(void)
{
	ft_putendl("invalid map");
	exit(0);
}

int			check_file(char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	read(fd, "", 0);
	i = get_next_line(fd, &line);
	if (i == 0 || i == -1)
		return (0);
	free(line);
	return (1);
}

int			check_wall(t_map *a)
{
	int	i;

	i = -1;
	while (++i < a->map_w)
		if (a->map[0][i] == 0 || a->map[a->map_h - 1][i] == 0)
			return (0);
	return (1);
}

int			valid_string(t_map *a, char **mas)
{
	int		i;

	i = 0;
	if (a->map_w == 0)
		while (mas[a->map_w] && a->map_w <= 400)
			a->map_w++;
	while (mas[i] && i <= 400)
		i++;
	if (i > 400 || a->map_w > 400)
		return (0);
	if (i != a->map_w || (a->map_h > 0 && i == 0))
		return (0);
	return (1);
}

void		open_file(int argc, char *filename, t_map *m)
{
	if (argc == 1)
	{
		ft_putendl("usage ./wolf3d map");
		exit(0);
	}
	if (argc > 2)
	{
		ft_putendl("too much options");
		ft_putendl("usage ./wolf3d map");
		exit(0);
	}
	if (!ft_read(filename, m))
		merror();
}
