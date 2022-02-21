#include "ft_struct.h"

void	draw_textur(t_all *all, float dist, float i, float j)
{
	if (all->coordin.ix >= 0 && all->coordin.ix < all->width \
	&& all->plr.c[(int)all->coordin.ix] >= dist)
	{
		i = (all->coordin.ix - all->coordin.proj_we) \
		/ ((float)all->coordin.sc / all->imgs.img_w);
		all->coordin.jy = all->coordin.proj_height;
		while (all->coordin.jy < all->coordin.sc + all->coordin.proj_height)
		{
			if (all->coordin.jy >= 0 && all->coordin.jy < all->height)
			{
				j = (all->coordin.jy - all->coordin.proj_height) \
				/ ((float)all->coordin.sc / all->imgs.img_h);
				all->coordin.color = my_pix_get(&all->imgs, i, j);
				if (all->coordin.color != 0)
					my_mlx_pixel_put(&all->win, all->coordin.ix, \
					all->coordin.jy, all->coordin.color);
			}
			all->coordin.jy++;
		}
	}
}

void	draw_sprite1(t_all *all, float x, float y, float dist)
{
	float	teta;
	float	i;
	float	j;

	i = 0;
	j = 0;
	teta = atan2(y - all->plr.y, x - all->plr.x);
	while (teta - all->plr.direction > M_PI)
		teta -= 2 * M_PI;
	while (teta - all->plr.direction < -M_PI)
		teta += 2 * M_PI;
	if (2 * (teta - all->plr.direction) < -M_PI_2 \
	|| 2 * (teta - all->plr.direction) > M_PI_2)
		return ;
	all->coordin.sc = (int)(all->height / dist);
	all->coordin.proj_we = -cos(2 * (teta - all->plr.direction) \
	+ M_PI_2) * all->width + all->width / 2 - all->coordin.sc / 2;
	all->coordin.proj_height = all->height / 2 - all->coordin.sc / 2;
	all->coordin.ix = all->coordin.proj_we;
	while (all->coordin.ix < all->coordin.sc + all->coordin.proj_we)
	{
		draw_textur(all, dist, i, j);
		all->coordin.ix++;
	}
}

static void	ft_swap(t_all *all, int i, int j)
{
	float	x;
	float	y;
	float	codirdis;

	codirdis = all->obj[i].distance;
	x = all->obj[i].x;
	y = all->obj[i].y;
	all->obj[i].distance = all->obj[j].distance;
	all->obj[i].x = all->obj[j].x;
	all->obj[i].y = all->obj[j].y;
	all->obj[j].distance = codirdis;
	all->obj[j].x = x;
	all->obj[j].y = y;
}

static void	ft_sortingspr(t_all *all)
{
	int	i;
	int	j;
	int	max;
	int	flag;

	i = 0;
	while (i < all->count)
	{
		max = all->obj[i].distance;
		flag = -1;
		j = i;
		while (++j < all->count)
		{
			if (all->obj[j].distance > max)
			{
				max = all->obj[j].distance;
				flag = j;
			}
		}
		if (flag != -1)
			ft_swap(all, i, flag);
		i++;
	}
}

void	col_tex(t_all *all)
{
	int	g;
	int	k;

	g = 0;
	k = 0;
	if (all->count >= 0)
	{
		while (g <= all->count)
		{
			all->obj[g].distance = sqrt(pow(all->plr.x - all->obj[g].x, 2) \
			+ pow(all->plr.y - all->obj[g].y, 2));
			g++;
		}
		ft_sortingspr(all);
		while (k <= all->count)
		{
			draw_sprite1(all, all->obj[k].x, all->obj[k].y, \
			all->obj[k].distance);
			k++;
		}
	}
}
