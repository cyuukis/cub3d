/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:53:13 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/27 20:24:39 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	ft_parser_ea(t_all *len, char *map)
{
	len->len_ea = 1;
	len->sum = len->sum + len->len_ea;
	len->textur_ea = ft_split(map + 2, ' ');
	free(map);
	len->imgea.img = mlx_xpm_file_to_image(len->win.mlx, \
	*len->textur_ea, &len->imgea.img_w, &len->imgea.img_h);
	if (len->imgea.img == NULL)
		exit_error();
	len->imgea.addr = mlx_get_data_addr(len->imgea.img, \
	&len->imgea.bpp, &len->imgea.line_l, &len->imgea.en);
	delete_textur(len->textur_ea);
}

void	ft_parser_s(t_all *len, char *map)
{
	len->len_s = 1;
	len->sum = len->sum + len->len_s;
	len->textur_s = ft_split(map + 1, ' ');
	free(map);
	len->imgs.img = mlx_xpm_file_to_image(len->win.mlx, \
	*len->textur_s, &len->imgs.img_w, &len->imgs.img_h);
	if (len->imgs.img == NULL)
		exit_error();
	len->imgs.addr = mlx_get_data_addr(len->imgs.img, \
	&len->imgs.bpp, &len->imgs.line_l, &len->imgs.en);
	delete_textur(len->textur_s);
}

void	ft_parser_f(t_all *len, char *map, char *str)
{
	len->len_f = 1;
	len->sum = len->sum + len->len_f;
	map++;
	len->colors.fo = ft_atoi(map);
	str = ft_strchr(map, ',');
	parser_exitfc(str);
	map = str;
	map++;
	len->colors.fb = ft_atoi(map);
	str = ft_strchr(map, ',');
	parser_exitfc(str);
	map = str;
	map++;
	len->colors.ft = ft_atoi(map);
	str = "";
	str = ft_strchr(map, ',');
	if (str != '\0')
		exit_error();
	if (len->colors.fo > 255 || len->colors.fb > 255 || len->colors.ft > 255)
		exit_error();
	if (len->colors.fo <= -1 || len->colors.fb <= -1 || len->colors.ft <= -1)
		exit_error();
	ft_colorf(len);
}

void	ft_parser_c(t_all *len, char *map, char *str)
{
	len->len_c = 1;
	len->sum = len->sum + len->len_f;
	map++;
	len->colors.co = ft_atoi(map);
	str = ft_strchr(map, ',');
	parser_exitfc(str);
	map = str;
	map++;
	len->colors.cb = ft_atoi(map);
	str = ft_strchr(map, ',');
	parser_exitfc(str);
	map = str;
	map++;
	len->colors.ct = ft_atoi(map);
	str = "";
	str = ft_strchr(map, ',');
	if (str != '\0')
		exit_error();
	if (len->colors.co > 255 || len->colors.cb > 255 || len->colors.ct > 255)
		exit_error();
	if (len->colors.co <= -1 || len->colors.cb <= -1 || len->colors.ct <= -1)
		exit_error();
	ft_colorc(len);
	free(str);
	str = NULL;
}

void	ft_parser_map(t_all *len, char *map)
{
	char	*str;

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
