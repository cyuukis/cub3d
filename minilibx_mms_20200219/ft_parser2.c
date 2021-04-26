/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:53:13 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/26 18:53:41 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	ft_parser_ea(t_all *len, char *map)
{
	len->len_ea = 1;
	len->sum = len->sum + len->len_ea;
	map = map + 2;
	len->textur_ea = ft_split(map, ' ');
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
	map++;
	len->textur_s = ft_split(map, ' ');
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
		exit_error();
	if (len->colors.fbits_one > 255 || \
	len->colors.fbits_two > 255 || len->colors.fbits_three > 255)
		exit_error();
	if (len->colors.fbits_one < 0 || \
	len->colors.fbits_two < 0 || len->colors.fbits_three < 0)
		exit_error();
	ft_colorf(len);
	free(str);
	str = NULL;
}

void	ft_parser_c(t_all *len, char *map, char *str)
{
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
		exit_error();
	if (len->colors.cbits_one > 255 || \
	len->colors.cbits_two > 255 || len->colors.cbits_three > 255)
		exit_error();
	if (len->colors.cbits_one < 0 || \
	len->colors.cbits_two < 0 || len->colors.cbits_three < 0)
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
