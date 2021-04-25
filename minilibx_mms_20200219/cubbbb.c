/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubbbb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:18:51 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/25 20:12:32 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include "ft_struct.h"
#include "../libft11/libft.h"
#include <stdio.h>
#include <math.h>
#define OBJ " 102WESN"
#define OBJJ "02WESN"

void	make_map2(t_all *len)
{
	int		i;
	int		j;
	char	sym;

	j = -1;
	i = -1;
	while (++i < len->y)
	{
		while (++j < ft_strlen(len->map[i]))
		{
			sym = len->map[i][j];
			if (!(ft_strrchr(OBJ, sym)))
				exit_error();
			if (ft_strrchr(OBJJ, sym))
				(((len->map[i - 1][j] != ' ') && (len->map[i + 1][j] != ' ')
				&& (len->map[i][j + 1] != ' ') && (len->map[i][j - 1] != ' ')
				&& (len->map[i - 1][j - 1] != ' ') && (len->map[i - 1][j + 1] != ' ')
				&& (len->map[i + 1][j - 1] != ' ') && (len->map[i + 1][j + 1] != ' '))
				? ft_parses_map(i, j, len->map[i][j], len) : exit_error());
		}
		//printf("|%s|\n", len->map[i]);
		//printf("\n");
		j = -1;
	}
	if (len->plr.flag != 0)
		exit_error();
	make_map3(len);
}
