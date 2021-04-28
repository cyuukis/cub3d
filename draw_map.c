/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:19:30 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/28 15:47:26 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	ft_parses_utech(t_all *len, char *map)
{
	if (*map == 'R' || *map == 'F' || *map == 'C')
		free(len->str_first);
}

int	x_close(int keycode, t_all *all)
{
	keycode = 0;
	ft_memset(&all, 0, sizeof(all));
	exit(1);
}

int	key(int keycode, t_all *all)
{
	if (keycode == 123)
		all->plr.direction -= 0.1;
	if (keycode == 124)
		all->plr.direction += 0.1;
	if (keycode == 13)
		key_w(all);
	if (keycode == 1)
		key_s(all);
	if (keycode == 0)
		key_a(all);
	if (keycode == 2)
		key_d(all);
	if (keycode == 53)
		exit(1);
	plr_luch(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	return (0);
}

void	draw_map(t_all *map, int argc, char *argv)
{
	map->win.mlx = mlx_init();
	map->win.win = mlx_new_window(map->win.mlx, map->width, \
	map->height, "cub3D");
	map->win.img = mlx_new_image(map->win.mlx, map->width, map->height);
	map->win.addr = mlx_get_data_addr(map->win.img, \
	&map->win.bpp, &map->win.line_l, &map->win.en);
	if (argc == 3)
	{
		if (ft_strncmp(argv, "--save", 7) == 0)
		{
			new_bmp(map);
			exit(1);
		}
		else
		{
			exit_error();
		}
	}
	plr_luch(map);
	mlx_hook(map->win.win, 2, 1L << 0, key, map);
	mlx_hook(map->win.win, 17, 1L << 17, x_close, map);
	mlx_put_image_to_window(map->win.mlx, map->win.win, map->win.img, 0, 0);
	mlx_loop(map->win.mlx);
}
