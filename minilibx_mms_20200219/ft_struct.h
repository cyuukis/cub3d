/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:55:15 by cyuuki            #+#    #+#             */
/*   Updated: 2021/03/25 20:16:26 by cyuuki           ###   ########.fr       */
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

typedef struct	s_ingno {
	void		*no_img;
	char		*no_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_wno;
	int			img_hno;
	int			len_no;
}				t_imgno;

typedef struct	s_ingso {
	void		*so_img;
	char		*so_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_wso;
	int			img_hso;
	int			len_so;
}				t_imgso;

typedef struct	s_ingwe {
	void		*we_img;
	char		*we_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_wwe;
	int			img_hwe;
	int			len_we;
}				t_imgwe;

typedef struct	s_ingea {
	void		*ea_img;
	char		*ea_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_wea;
	int			img_hea;
	int			len_ea;
}				t_imgea;

typedef struct	s_imgs {
	void		*s_img;
	char		*s_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_ws;
	int			img_hs;
	int			len_s;
}				t_imgs;

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
}				t_all;
