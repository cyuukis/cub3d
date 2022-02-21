#include "ft_struct.h"

void	key_w(t_all *all)
{
	all->plr.y += sin(all->plr.direction);
	all->plr.x += cos(all->plr.direction);
	if (all->map[(int)all->plr.y][(int)all->plr.x] != '1')
		my_mlx_pixel_put(&all->win, all->plr.x * 1, \
		all->plr.y * 1, 0x000FF00);
	else
	{
		all->plr.y -= sin(all->plr.direction);
		all->plr.x -= cos(all->plr.direction);
		my_mlx_pixel_put(&all->win, \
		all->plr.x * 1, all->plr.y * 1, 0x000FF00);
	}
}

void	key_s(t_all *all)
{
	all->plr.y -= sin(all->plr.direction);
	all->plr.x -= cos(all->plr.direction);
	if (all->map[(int)all->plr.y][(int)all->plr.x] != '1')
		my_mlx_pixel_put(&all->win, all->plr.x * 1, \
		all->plr.y * 1, 0x000FF00);
	else
	{
		all->plr.y += sin(all->plr.direction);
		all->plr.x += cos(all->plr.direction);
		my_mlx_pixel_put(&all->win, \
		all->plr.x * 1, all->plr.y * 1, 0x000FF00);
	}
}

void	key_a(t_all *all)
{
	all->plr.x += sin(all->plr.direction);
	all->plr.y -= cos(all->plr.direction);
	if (all->map[(int)all->plr.y][(int)all->plr.x] != '1')
	{
		my_mlx_pixel_put(&all->win, \
		all->plr.x * 1, all->plr.y * 1, 0x000FF00);
	}
	else
	{
		all->plr.x -= sin(all->plr.direction);
		all->plr.y += cos(all->plr.direction);
		my_mlx_pixel_put(&all->win, \
		all->plr.x * 1, all->plr.y * 1, 0x000FF00);
	}
}

void	key_d(t_all *all)
{
	all->plr.x -= sin(all->plr.direction);
	all->plr.y += cos(all->plr.direction);
	if (all->map[(int)all->plr.y][(int)all->plr.x] != '1')
		my_mlx_pixel_put(&all->win, \
	all->plr.x * 1, all->plr.y * 1, 0x000FF00);
	else
	{
		all->plr.x += sin(all->plr.direction);
		all->plr.y -= cos(all->plr.direction);
		my_mlx_pixel_put(&all->win, \
		all->plr.x * 1, all->plr.y * 1, 0x000FF00);
	}
}
