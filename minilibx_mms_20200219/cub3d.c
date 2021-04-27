/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:33:43 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/27 20:37:35 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	ft_colorf(t_all *all)
{
	int	r;
	int	g;
	int	b;

	r = all->colors.fo << 1;
	g = all->colors.fb << 8;
	b = all->colors.ft << 0;
	all->colors.fbits_color = r | g | b;
}

void	ft_colorc(t_all *all)
{
	int	r;
	int	g;
	int	b;

	r = all->colors.co << 1;
	g = all->colors.cb << 8;
	b = all->colors.ct << 0;
	all->colors.cbits_color = r | g | b;
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	write(2, "Error in the parser\n", 20);
	exit(1);
}

int	my_pix_get(t_win *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

// char	**delete_textur(char **textur)
// {
// 	int	i;

// 	i = 0;
// 	while (textur[i])
// 		free(textur[i++]);
// 	free(textur);
// 	return (NULL);
// }

// void	ft_param(t_all *len)
// {
// 	len->flag = 0;
// 	len->sum = 0;
// 	len->len_r = -1;
// 	len->len_we = -1;
// 	len->len_no = -1;
// 	len->len_ea = -1;
// 	len->len_s = -1;
// 	len->len_so = -1;
// 	len->len_c = -1;
// 	len->len_f = -1;
// 	len->colors.fo = -1;
// 	len->colors.fb = -1;
// 	len->colors.ft = -1;
// 	len->colors.co = -1;
// 	len->colors.cb = -1;
// 	len->colors.ct = -1;
// }

// void	parser_exitfc(char *str)
// {
// 	if (str == NULL)
// 		exit_error();
// }
