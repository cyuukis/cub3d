/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:14:05 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/27 21:45:52 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

static void	ft_parses_map2(int y, int x, t_all *all)
{
	static int	count;

	all->obj[count].x = x + 0.5;
	all->obj[count].y = y + 0.5;
	count++;
	all->count = count;
}

void	make_map3(t_all *len)
{
	int		i;
	int		j;
	char	sym;

	i = -1;
	j = -1;
	len->obj = malloc(100 * len->plr.place_two);
	if (len->obj == NULL)
		exit_error();
	while (++i < len->y)
	{
		while (++j < ft_strlen(len->map[i]))
		{
			sym = len->map[i][j];
			if (ft_strrchr("2", sym))
				ft_parses_map2(i, j, len);
		}
		j = -1;
	}
}
