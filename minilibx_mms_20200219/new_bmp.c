/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:05:11 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/27 20:34:09 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	arr_s(unsigned char *file, int color, int size)
{
	int	i;

	i = 0;
	while (i < size / 8)
	{
		file[i] = color >> i * 8;
		i++;
	}
}

void	drawbmp3(t_drwbmp *bmp, t_all *all)
{
	int	x;
	int	h;
	int	w;
	int	color;
	int	bit;

	h = all->height;
	w = all->width;
	bmp->file = ft_calloc(bmp->size_d, 1);
	while (h--)
	{
		x = 0;
		while (x < w)
		{
			color = my_pix_get(&all->win, x, h);
			arr_s(bmp->file + bit, color, 24);
			bit += 3;
			x++;
		}
		bit = bit + bmp->file_ps;
	}
	write(bmp->open, bmp->file, bmp->size_d);
	free(bmp->file);
}

void	drawbmp2(t_drwbmp *bmp, t_all *all)
{
	bmp->file = ft_calloc(40, 1);
	bmp->file[0] = 40;
	bmp->file[1] = 40 >> 8;
	bmp->file[2] = 40 >> 8 * 2;
	bmp->file[3] = 40 >> 8 * 3;
	bmp->file[4] = all->width;
	bmp->file[5] = all->width >> 8;
	bmp->file[6] = all->width >> 8 * 2;
	bmp->file[7] = all->width >> 8 * 3;
	bmp->file[8] = all->height;
	bmp->file[9] = all->height >> 8;
	bmp->file[10] = all->height >> 8 * 2;
	bmp->file[11] = all->height >> 8 * 3;
	bmp->file[12] = 1;
	bmp->file[14] = 24;
	bmp->file[20] = bmp->size_d;
	bmp->file[21] = bmp->size_d >> 8;
	bmp->file[22] = bmp->size_d >> 8 * 2;
	bmp->file[23] = bmp->size_d >> 8 * 3;
	write(bmp->open, bmp->file, 40);
	free(bmp->file);
	bmp->file = NULL;
	drawbmp3(bmp, all);
}

void	drawbmp(t_all *all, int width, int height, t_drwbmp *bmp)
{
	int	sum;

	bmp->file_ps = (4 - (all->width * 3) % 4) % 4;
	bmp->size_d = all->width * all->height * 3 + all->height * bmp->file_ps;
	bmp->file = ft_calloc(14, 1);
	sum = 14 + 40 + bmp->size_d;
	bmp->file[0] = 'B';
	bmp->file[1] = 'M';
	bmp->file[2] = sum;
	bmp->file[3] = sum >> 8;
	bmp->file[4] = sum >> 8 * 2;
	bmp->file[5] = sum >> 8 * 3;
	bmp->file[10] = 54;
	bmp->file[11] = 54 >> 8;
	bmp->file[12] = 54 >> 8 * 2;
	bmp->file[13] = 54 >> 8 * 3;
	write(bmp->open, bmp->file, 14);
	free(bmp->file);
	bmp->file = NULL;
	drawbmp2(bmp, all);
}

void	new_bmp(t_all *all)
{
	t_drwbmp	bmp;

	plr_luch(all);
	bmp.open = open("screen_cub.bmp", O_CREAT | O_WRONLY | O_TRUNC, \
		S_IREAD | S_IWRITE);
	drawbmp(all, all->width, all->height, &bmp);
	close(bmp.open);
}
