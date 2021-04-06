/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:35:11 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/06 22:35:22 by cyuuki           ###   ########.fr       */
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

void	direction_player(char sym, t_all *dote)
{
	if (sym == 'N')
	{
		dote->plr.direction = 3 * M_PI_2;
	}
	if (sym == 'S')
	{
		dote->plr.direction = M_PI_2;
	}
	if (sym == 'W')
	{
		dote->plr.direction = M_PI;
	}
	if (sym == 'E')
	{
		dote->plr.direction = 0;
	}
}

void	ft_parses_map2(int y, int x, t_all *all)
{
	static	int		count;
	float			dx;
	float			dy;

	all->obj[count].x = x + 0.5;
	all->obj[count].y = y + 0.5;
	count++;
	all->count = count;
}
