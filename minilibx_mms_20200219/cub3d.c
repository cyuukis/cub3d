/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:33:43 by cyuuki            #+#    #+#             */
/*   Updated: 2021/03/01 19:53:06 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

int main()
{
	void *mlx = NULL;
	void *win = NULL;
	int x = 0;
	int y = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "test");
	while (y++ < 480)
	{
		x = 0;
		while (x++ < 320)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
		}

	}
	mlx_loop(mlx);
	return (0);
}
