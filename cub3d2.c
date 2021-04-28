/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:37:48 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/27 20:38:04 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

char	**delete_textur(char **textur)
{
	int	i;

	i = 0;
	while (textur[i])
		free(textur[i++]);
	free(textur);
	return (NULL);
}

void	ft_param(t_all *len)
{
	len->flag = 0;
	len->sum = 0;
	len->len_r = -1;
	len->len_we = -1;
	len->len_no = -1;
	len->len_ea = -1;
	len->len_s = -1;
	len->len_so = -1;
	len->len_c = -1;
	len->len_f = -1;
	len->colors.fo = -1;
	len->colors.fb = -1;
	len->colors.ft = -1;
	len->colors.co = -1;
	len->colors.cb = -1;
	len->colors.ct = -1;
}

void	parser_exitfc(char *str)
{
	if (str == NULL)
		exit_error();
}
