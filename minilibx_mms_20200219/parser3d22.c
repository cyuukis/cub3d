/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3d22.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:03:15 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/06 22:36:37 by cyuuki           ###   ########.fr       */
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

void	ft_colorf(t_all *all)
{
	int r;
	int g;
	int b;

	r = all->colors.fbits_one << 1;
	g = all->colors.fbits_two << 8;
	b = all->colors.fbits_three << 0;
	all->colors.fbits_color = r | g | b;
}

void	ft_colorc(t_all *all)
{
	int r;
	int g;
	int b;

	r = all->colors.cbits_one << 1;
	g = all->colors.cbits_two << 8;
	b = all->colors.cbits_three << 0;
	all->colors.cbits_color = r | g | b;
}

void	ft_parser_c(t_all *len, char *map)
{
	char *str;

	if (len->len_c != -1)
		return ;//ошибка
	len->len_c = 1;
	len->sum = len->sum + len->len_f;
	map++;
	len->colors.cbits_one = ft_atoi(map);
	str = ft_strchr(map, ',');
	map = str;
	map++;
	len->colors.cbits_two = ft_atoi(map);
	str = ft_strchr(map, ',');
	map = str;
	map++;
	len->colors.cbits_three = ft_atoi(map);
	str = "";
	str = ft_strchr(map, ',');
	if (str != '\0')
		return ;//ошибка
	ft_cpars(len);
	ft_colorc(len);
}

void	ft_parser_map(t_all *len, char *map)
{
	char *str;

	str = NULL;
	if (*map == ' ')
	{
		while (*map != '\0')
		{
			if (*map == '1')
			{
				len->flag = 1;
				break ;
			}
			map++;
		}
	}
	if (*map == '1')
		len->flag = 1;
}
