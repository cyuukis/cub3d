/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_rectl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:10:34 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/26 18:11:38 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

static void	direction_player(char sym, t_all *dote)
{
	if (sym == 'N')
		dote->plr.direction = 3 * M_PI_2;
	if (sym == 'S')
		dote->plr.direction = M_PI_2;
	if (sym == 'W')
		dote->plr.direction = M_PI;
	if (sym == 'E')
		dote->plr.direction = 0;
}

static void	ft_parses_map(int i, int j, char sym, t_all *len)
{
	if ((sym == 'W' || sym == 'N' || sym == 'E' || sym == 'S'))
	{
		direction_player(sym, len);
		len->plr.x = j + 0.5;
		len->plr.y = i + 0.5;
		len->plr.flag = len->plr.flag + 1;
	}
	if (sym == '2')
	{
		len->plr.place_two++;
	}
}

void	make_map_rectl(t_all *len, int i, int j)
{
	if ((len->map[i - 1][j] != ' ') && (len->map[i + 1][j] != ' ') \
	&& (len->map[i][j + 1] != ' ') && (len->map[i][j - 1] != ' ') \
	&& (len->map[i - 1][j - 1] != ' ') && (len->map[i - 1][j + 1] != ' ') \
	&& (len->map[i + 1][j - 1] != ' ') \
	&& (len->map[i + 1][j + 1] != ' '))
		ft_parses_map(i, j, len->map[i][j], len);
	else
		exit_error();
}
