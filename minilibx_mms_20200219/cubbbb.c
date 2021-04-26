/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubbbb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:18:51 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/26 16:45:10 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include "ft_struct.h"
#include "../libft11/libft.h"
#include <stdio.h>
#include <math.h>
#define OBJ " 102WESN"
#define OBJJ "02WESN"

void	ft_colorf(t_all *all)
{
	int	r;
	int	g;
	int	b;

	r = all->colors.fbits_one << 1;
	g = all->colors.fbits_two << 8;
	b = all->colors.fbits_three << 0;
	all->colors.fbits_color = r | g | b;
}

void	ft_colorc(t_all *all)
{
	int	r;
	int	g;
	int	b;

	r = all->colors.cbits_one << 1;
	g = all->colors.cbits_two << 8;
	b = all->colors.cbits_three << 0;
	all->colors.cbits_color = r | g | b;
}
