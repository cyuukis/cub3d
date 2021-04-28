/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:34:09 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/26 18:34:15 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

void	my_bit_images_no(t_all *all, float start, int y, float h)
{
	float	pix;

	pix = h / all->imgno.img_h;
	all->y_tex = ((float)y - start) / pix;
}

void	my_bit_images_so(t_all *all, float start, int y, float h)
{
	float	pix;

	pix = h / all->imgso.img_h;
	all->y_tex = ((float)y - start) / pix;
}

void	my_bit_images_we(t_all *all, float start, int y, float h)
{
	float	pix;

	pix = h / all->imgwe.img_h;
	all->y_tex = ((float)y - start) / pix;
}

void	my_bit_images_ea(t_all *all, float start, int y, float h)
{
	float	pix;

	pix = h / all->imgea.img_h;
	all->y_tex = ((float)y - start) / pix;
}
