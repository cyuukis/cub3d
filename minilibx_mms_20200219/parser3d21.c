/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3d21.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:01:02 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/06 22:01:43 by cyuuki           ###   ########.fr       */
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

void	ft_parser_ea(t_all *len, char *map)
{
	if (len->len_ea != -1)
		return ;// ошибка
	len->len_ea = 1;
	len->sum = len->sum + len->len_ea;
	map = map + 2;
	len->textur_ea = *ft_split(map, ' ');
	if (!(len->imgea.img = mlx_xpm_file_to_image(len->win.mlx,
	len->textur_ea, &len->imgea.img_w, &len->imgea.img_h)))
		return ;//ошибка какая-то
	len->imgea.addr = mlx_get_data_addr(len->imgea.img,
	&len->imgea.bpp, &len->imgea.line_l, &len->imgea.en);
}

void	ft_parser_s(t_all *len, char *map)
{
	if (len->len_s != -1)
		return ; // ошибка
	len->len_s = 1;
	len->sum = len->sum + len->len_s;
	map++;
	len->textur_s = *ft_split(map, ' ');
	if (!(len->imgs.img = mlx_xpm_file_to_image(len->win.mlx,
	len->textur_s, &len->imgs.img_w, &len->imgs.img_h)))
		return ;//ошибка какая-то
	len->imgs.addr = mlx_get_data_addr(len->imgs.img,
	&len->imgs.bpp, &len->imgs.line_l, &len->imgs.en);
}

void	ft_fpars(t_all *len)
{
	if (len->colors.fbits_one > 255 ||
	len->colors.fbits_two > 255 || len->colors.fbits_three > 255)
		return ;// ошибка
	if (len->colors.fbits_one < 0 ||
	len->colors.fbits_two < 0 || len->colors.fbits_three < 0)
		return ;//ошибка
}

void	ft_parser_f(t_all *len, char *map)
{
	char *str;

	if (len->len_f != -1)
		return ; //ошибка
	len->len_f = 1;
	len->sum = len->sum + len->len_f;
	map++;
	len->colors.fbits_one = ft_atoi(map);
	str = ft_strchr(map, ',');
	map = str;
	map++;
	len->colors.fbits_two = ft_atoi(map);
	str = ft_strchr(map, ',');
	map = str;
	map++;
	len->colors.fbits_three = ft_atoi(map);
	str = "";
	str = ft_strchr(map, ',');
	if (str != '\0')
		return ;//ошибка
	ft_fpars(len);
	ft_colorf(len);
}

void	ft_cpars(t_all *len)
{
	if (len->colors.cbits_one > 255 ||
	len->colors.cbits_two > 255 || len->colors.cbits_three > 255)
		return ;// ошибка
	if (len->colors.cbits_one < 0 ||
	len->colors.cbits_two < 0 || len->colors.cbits_three < 0)
		return ;//ошибка
}
