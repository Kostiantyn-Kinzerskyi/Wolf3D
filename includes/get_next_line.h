/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:57:10 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/09 16:34:49 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 9999

typedef struct	s_struct
{
	int			r;
	int			i;
}				t_struct;

int				get_next_line(const int fd, char **line);

#endif
