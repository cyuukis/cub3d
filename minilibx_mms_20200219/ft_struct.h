/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:55:15 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/27 20:30:31 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
# include "mlx.h"
# include <stdlib.h>
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include "ft_struct.h"
# include "../libft11/libft.h"
# include <stdio.h>
# include <math.h>
# define OBJ " 102WESN"
# define OBJJ "02WESN"

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
	int		line_l;
	int		bpp;
	int		en;
	int		img_w;
	int		img_h;
}				t_win;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	float	x;
	float	y;
	float	distance;
}				t_map;

typedef struct s_plr
{
	float		direction;
	float		x;
	float		y;
	float		angel;
	float		start;
	float		end;
	int			flag;
	int			place_two;
	float		*c;
}				t_plr;

typedef struct s_colors
{
	int			fo;
	int			fb;
	int			ft;
	int			fbits_color;
	int			co;
	int			cb;
	int			ct;
	int			cbits_color;
}				t_colors;

typedef struct s_coordin
{
	int	proj_height;
	int	proj_we;
	int	ix;
	int	jy;
	int	color;
	int	sc;
}				t_coordin;

typedef struct s_drwbmp
{
	unsigned char	*file;
	int				open;
	int				file_ps;
	int				size_d;
}				t_drwbmp;

typedef struct s_all
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
	float		luch_x;
	float		luch_y;
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
	char		**textur_no;
	char		**textur_so;
	char		**textur_we;
	char		**textur_ea;
	char		**textur_s;
	int			y;
	float		fov;
	int			count;
}				t_all;

int		main(int argc, char **argv);
void	maping(t_all *len, t_list *head, int max, char *line);
void	exit_error(void);
void	make_map_rectl(t_all *len, int i, int j);
void	make_map3(t_all *len);
void	draw_map(t_all *map, int argc, char *argv);
void	plr_luch(t_all *all);
int		x_close(int keycode, t_all *all);
int		key(int keycode, t_all *all);
void	draw_we(t_all *all, int y, float a, int i);
void	draw_sn(t_all *all, int y, float a, int i);
void	my_bit_images_no(t_all *all, float start, int y, float h);
void	my_bit_images_so(t_all *all, float start, int y, float h);
void	my_bit_images_we(t_all *all, float start, int y, float h);
void	my_bit_images_ea(t_all *all, float start, int y, float h);
void	col_tex(t_all *all);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
int		my_pix_get(t_win *data, int x, int y);
char	**delete_textur(char **textur);
void	ft_parses(char *map, t_all *len);
void	ft_parser_ea(t_all *len, char *map);
void	ft_parser_s(t_all *len, char *map);
void	ft_parser_f(t_all *len, char *map, char *str);
void	ft_parser_c(t_all *len, char *map, char *str);
void	ft_parser_map(t_all *len, char *map);
void	key_d(t_all *all);
void	key_a(t_all *all);
void	key_s(t_all *all);
void	key_w(t_all *all);
void	draw_snwe(t_all *all, int y, float a, int i);
void	ft_colorf(t_all *all);
void	ft_colorc(t_all *all);
void	ft_param(t_all *len);
void	new_bmp(t_all *all);
void	parser_exitfc(char *str);
void	ft_parses_utech(t_all *len, char *map);

#endif
