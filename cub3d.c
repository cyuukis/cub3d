#include "ft_struct.h"

void	ft_colorf(t_all *all)
{
	int	r;
	int	g;
	int	b;

	r = all->colors.fo << 16;
	g = all->colors.fb << 8;
	b = all->colors.ft << 0;
	all->colors.fbits_color = r | g | b;
}

void	ft_colorc(t_all *all)
{
	int	r;
	int	g;
	int	b;

	r = all->colors.co << 16;
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
