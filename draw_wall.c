/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:32:32 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/26 18:32:34 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	draw_sn(t_all *all, int y, float a, int i)
{
	float	start;
	int		color;

	start = all->height / 2 - a / 2;
	if (all->plr.angel >= 0 && all->plr.angel <= M_PI)
	{
		all->luch_x = all->luch_x - (int)all->luch_x;
		all->x_tex = all->luch_x * all->imgso.img_w;
		my_bit_images_so(all, start, y, a);
		color = my_pix_get(&all->imgso, all->x_tex, all->y_tex);
		my_mlx_pixel_put(&all->win, i, y, color);
	}
	else if (all->plr.angel >= M_PI || all->plr.angel <= 2 * M_PI)
	{
		all->luch_x = all->luch_x - (int)all->luch_x;
		all->x_tex = all->luch_x * all->imgno.img_w;
		my_bit_images_no(all, start, y, a);
		color = my_pix_get(&all->imgno, all->x_tex, all->y_tex);
		my_mlx_pixel_put(&all->win, i, y, color);
	}
}

void	draw_we(t_all *all, int y, float a, int i)
{
	float	start;
	int		color;

	start = all->height / 2 - a / 2;
	if (all->plr.angel >= M_PI_2 && all->plr.angel <= 3 * M_PI_2)
	{
		all->luch_y = all->luch_y - (int)all->luch_y;
		all->x_tex = all->luch_y * all->imgwe.img_w;
		my_bit_images_we(all, start, y, a);
		color = my_pix_get(&all->imgwe, all->x_tex, all->y_tex);
		my_mlx_pixel_put(&all->win, i, y, color);
	}
	else if (all->plr.angel >= 3 * M_PI_2 || all->plr.angel <= 9.42)
	{
		all->luch_y = all->luch_y - (int)all->luch_y;
		all->x_tex = all->luch_y * all->imgea.img_w;
		my_bit_images_ea(all, start, y, a);
		color = my_pix_get(&all->imgea, all->x_tex, all->y_tex);
		my_mlx_pixel_put(&all->win, i, y, color);
	}
}
