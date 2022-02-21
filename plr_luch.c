#include "ft_struct.h"

void	draw_snwe(t_all *all, int y, float a, int i)
{
	if (all->plr.angel < 0)
		all->plr.angel += 2 * M_PI;
	if (all->plr.angel > 2 * M_PI)
		all->plr.angel -= 2 * M_PI;
	if (all->flagno == -4)
		draw_sn(all, y, a, i);
	else if (all->flagno == 4)
		draw_we(all, y, a, i);
}

void	wall_3d(t_all *all, int i)
{
	float	start;
	float	end;
	int		y;
	float	a;

	a = 0;
	y = 0;
	if (all->plr.c[i] > 0)
		a = all->height / (all->plr.c[i] * \
		cos(all->plr.angel - all->plr.direction));
	start = all->height / 2 - a / 2;
	end = all->height / 2 + a / 2;
	while (y < start)
	{
		my_mlx_pixel_put(&all->win, i, y, all->colors.fbits_color);
		y++;
	}
	while (y < all->height && y < end)
	{
		draw_snwe(all, y, a, i);
		y++;
	}
	while (++y < all->height)
		my_mlx_pixel_put(&all->win, i, y, all->colors.cbits_color);
}

void	col_luch(t_all *all, int i)
{
	float	step;

	step = all->fov / all->width;
	all->plr.c[i] = 0;
	all->luch_x = all->plr.x + all->plr.c[i] * cos(all->plr.angel);
	all->luch_y = all->plr.y + all->plr.c[i] * sin(all->plr.angel);
	while (1)
	{
		all->luch_x = all->plr.x + all->plr.c[i] * cos(all->plr.angel);
		if (all->map[(int)all->luch_y][(int)all->luch_x] == '1')
		{
			all->flagno = 4;
			break ;
		}
		all->luch_y = all->plr.y + all->plr.c[i] * sin(all->plr.angel);
		if (all->map[(int)all->luch_y][(int)all->luch_x] == '1')
		{
			all->flagno = -4;
			break ;
		}
		all->plr.c[i] += 0.005F;
	}
	all->plr.angel += step;
	wall_3d(all, i);
}

void	plr_luch(t_all *all)
{
	int		i;

	all->fov = 0.5F;
	i = 0;
	all->plr.angel = all->plr.direction - all->fov / 2;
	while (i < all->width)
	{
		col_luch(all, i);
		i++;
	}
	col_tex(all);
}
