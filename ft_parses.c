/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:45:25 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/28 16:32:56 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	ft_parser_r(t_all *len, char *map)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	len->len_r = 1;
	len->sum = len->sum + len->len_r;
	len->width = ft_atoi(map + 1);
	str = ft_itoa(len->width);
	while (str[i] != '\0')
	{
		map++;
		i++;
	}
	len->height = ft_atoi(map + 2);
	if (len->width < 1 || len->height < 1)
		exit_error();
	if (len->w_width < len->width)
		len->width = len->w_width;
	if (len->w_height < len->height)
		len->height = len->w_height;
	free(str);
}

void	ft_parser_no(t_all *len, char *map)
{
	if(len->len_no == 1)
		exit_error();
	len->len_no = 1;
	len->sum = len->sum + len->len_no;
	len->textur_no = ft_split(map + 2, ' ');
	free(map);
	len->imgno.img = mlx_xpm_file_to_image(len->win.mlx, \
	*len->textur_no, &len->imgno.img_w, &len->imgno.img_h);
	if (len->imgno.img == NULL)
		exit_error();
	len->imgno.addr = mlx_get_data_addr(len->imgno.img, \
	&len->imgno.bpp, &len->imgno.line_l, &len->imgno.en);
	delete_textur(len->textur_no);
}

void	ft_parser_so(t_all *len, char *map)
{
	if(len->len_so == 1)
		exit_error();
	len->len_so = 1;
	len->sum = len->sum + len->len_so;
	len->textur_so = ft_split(map + 2, ' ');
	len->imgso.img = mlx_xpm_file_to_image(len->win.mlx, \
	*len->textur_so, &len->imgso.img_w, &len->imgso.img_h);
	if (len->imgso.img == NULL)
		exit_error();
	len->imgso.addr = mlx_get_data_addr(len->imgso.img, \
	&len->imgso.bpp, &len->imgso.line_l, &len->imgso.en);
	free(map);
	delete_textur(len->textur_so);
}

void	ft_parser_we(t_all *len, char *map)
{
	if(len->len_we == 1)
		exit_error();
	len->len_we = 1;
	len->sum = len->sum + len->len_we;
	len->textur_we = ft_split(map + 2, ' ');
	len->imgwe.img = mlx_xpm_file_to_image(len->win.mlx, \
	*len->textur_we, &len->imgwe.img_w, &len->imgwe.img_h);
	if (len->imgwe.img == NULL)
		exit_error();
	len->imgwe.addr = mlx_get_data_addr(len->imgwe.img, \
	&len->imgwe.bpp, &len->imgwe.line_l, &len->imgwe.en);
	delete_textur(len->textur_we);
	free(map);
}

void	ft_parses(char *map, t_all *len)
{
	char	*str;

	str = NULL;
	mlx_get_screen_size(len->win.mlx, &len->w_width, &len->w_height);
	if (*map == 'R')
		ft_parser_r(len, map);
	else if ((*map == 'N' && *(map + 1) == 'O'))
		ft_parser_no(len, map);
	else if ((*map == 'S' && *(map + 1) == 'O'))
		ft_parser_so(len, map);
	else if (*map == 'W' && *(map + 1) == 'E')
		ft_parser_we(len, map);
	else if (*map == 'E' && *(map + 1) == 'A')
		ft_parser_ea(len, map);
	else if (*map == 'S')
		ft_parser_s(len, map);
	else if (*map == 'F')
		ft_parser_f(len, map, str);
	else if (*map == 'C')
		ft_parser_c(len, map, str);
	else if (len->sum == 8 && (*map == '1' || *map == ' '))
		ft_parser_map(len, map);
	else if (len->sum > 8 || len->sum < 8)
		exit_error();
	ft_parses_utech(len, map);
}
