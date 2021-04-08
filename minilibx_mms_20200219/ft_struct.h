/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:55:15 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/08 20:00:10 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*addr;
	void		*img;
	int			line_l;
	int			bpp;
	int			en;
	int			img_w;
	int			img_h;
}				  t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_map
{
	float	x;
	float	y;
	//float	dir;
	float distance;
}				t_map;

typedef struct	s_plr //структура для игрока и луча
{
	float		direction;
	float		x;
	float		y;
	float		angel;
	float		start;
	float		end;
	int			flag;
	int			place_two;
}				t_plr;

typedef struct	s_colors {
	int			fbits_one;
	int			fbits_two;
	int			fbits_three;
	int			fbits_color;
	int			cbits_one;
	int			cbits_two;
	int			cbits_three;
	int			cbits_color;
}				t_colors;

typedef struct s_coordin
{
	float proj_height;
	float proj_we;
}	t_coordin;

typedef struct	s_all // структура для всего вместе
{
	t_win		win;
	t_plr		plr;
	t_map		*obj;
	t_win		imgno;
	t_win		imgso;
	t_win		imgwe;
	t_win		imgea;
	t_win		imgs;
	t_colors	colors;
	t_coordin	coordin;
	int			x_tex;
	int			y_tex;
	int			flagno;
	int			fd;
	int			flag;
	char		**map;
	char		*str_first;
	int			len_r;
	int			len_no;
	int			len_so;
	int			len_we;
	int			len_ea;
	int			len_c;
	int			len_f;
	int			len_s;
	int			sum;
	int			width;
	int			height;
	int			w_width;
	int			w_height;
	char		*textur_no;
	char		*textur_so;
	char		*textur_we;
	char		*textur_ea;
	char		*textur_s;
	int			y;
	float		fov;
	int			count;
}				t_all;
