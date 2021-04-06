/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:58:55 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/06 21:59:55 by cyuuki           ###   ########.fr       */
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

void	ft_parser_r(t_all *len, char *map)
{
	char *str;

	len->len_r = 1;
	len->sum = len->len_r;
	map++;
	len->width = ft_atoi(map);
	str = ft_itoa(len->width);
	while (*str != '\0')
	{
		map++;
		str++;
	}
	map++;
	len->height = ft_atoi(map);
	if (len->width < 1 || len->height < 1)
		return ;// тут ошибку надо написать
	((len->w_width < len->width) ? len->width = len->w_width
	: len->width);
	((len->w_height < len->height) ? len->height = len->w_height
	: len->height);
}

void	ft_parser_no(t_all *len, char *map)
{
	len->len_no = 1;
	len->sum = len->sum + len->len_no;
	map = map + 2;
	len->textur_no = *ft_split(map, ' ');
	printf("|%s|\n", len->textur_no);
	if (!(len->imgno.img = mlx_xpm_file_to_image(len->win.mlx,
	len->textur_no, &len->imgno.img_w, &len->imgno.img_h)))
		printf("%s\n", len->imgno.img);//return ;//ошибка какая-то
	len->imgno.addr = mlx_get_data_addr(len->imgno.img,
	&len->imgno.bpp, &len->imgno.line_l, &len->imgno.en);
}

void	ft_parser_so(t_all *len, char *map)
{
	len->len_so = 1;
	len->sum = len->sum + len->len_so;
	map = map + 2;
	len->textur_so = *ft_split(map, ' ');
	if (!(len->imgso.img = mlx_xpm_file_to_image(len->win.mlx,
	len->textur_so, &len->imgso.img_w, &len->imgso.img_h)))
		return ;//ошибка какая-то
	len->imgso.addr = mlx_get_data_addr(len->imgso.img,
	&len->imgso.bpp, &len->imgso.line_l, &len->imgso.en);
}

void	ft_parser_we(t_all *len, char *map)
{
	if (len->len_we != -1)
		return ; // ошибка
	len->len_we = 1;
	len->sum = len->sum + len->len_we;
	map = map + 2;
	len->textur_we = *ft_split(map, ' ');
	if (!(len->imgwe.img = mlx_xpm_file_to_image(len->win.mlx,
	len->textur_we, &len->imgwe.img_w, &len->imgwe.img_h)))
		return ;//ошибка какая-то
	len->imgwe.addr = mlx_get_data_addr(len->imgwe.img,
	&len->imgwe.bpp, &len->imgwe.line_l, &len->imgwe.en);
}

void	ft_parses(char *map, t_all *len)
{
	mlx_get_screen_size(len->win.mlx, &len->w_width, &len->w_height);
	if (*map == 'R' && len->len_r == -1)
		ft_parser_r(len, map);
	else if ((*map == 'N' && *(map + 1) == 'O') && len->len_no == -1)
		ft_parser_no(len, map);
	else if ((*map == 'S' && *(map + 1) == 'O') && len->len_so == -1)
		ft_parser_so(len, map);
	else if (*map == 'W' && *(map + 1) == 'E')
		ft_parser_we(len, map);
	else if (*map == 'E' && *(map + 1) == 'A')
		ft_parser_ea(len, map);
	else if (*map == 'S')
		ft_parser_s(len, map);
	else if (*map == 'F')
		ft_parser_f(len, map);
	else if (*map == 'C')
		ft_parser_c(len, map);
	else if (len->sum == 8 /*&& (*map == '1' || *map == ' ')*/)
		ft_parser_map(len, map);
	//printf("%d\n", len->flag);
	// else if (len->sum > 8)
	// {
	// 	exit(1);
	// }
}
