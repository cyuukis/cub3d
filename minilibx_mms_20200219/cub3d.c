/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:33:43 by cyuuki            #+#    #+#             */
/*   Updated: 2021/03/18 21:41:22 by cyuuki           ###   ########.fr       */
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

void	ft_colorf(t_colors *f_colors)
{
	t_colors f_c;
	int r;
	int g;
	int b;

	r = f_colors->fbits_one << 16;
	g = f_colors->fbits_two << 8;
	b = f_colors->fbits_three << 0;
	f_c.fbits_color = r | g | b;
}
void	ft_colorc(t_colors *f_colors)
{
	t_colors c_c;
	int r;
	int g;
	int b;

	r = f_colors->cbits_one << 16;
	g = f_colors->cbits_two << 8;
	b = f_colors->cbits_three << 0;
	c_c.cbits_color = r | g | b;
	//printf("%x", c_c.cbits_color);
}

void	direction_player(char sym, t_all *dote)
{
	if (sym == 'N')
	{
		dote->plr.direction = 3 * M_PI_2 / 2;
	}
	if (sym == 'S')
	{
		dote->plr.direction = M_PI_2 / 2;
	}
	if (sym == 'W')
	{
		dote->plr.direction = M_PI;
	}
	if (sym == 'E')
	{
		dote->plr.direction = 0;
	}
}

void exit_error()
{
	write(2, "Error\n",6);
	write(2,"Error in the parser\n", 20);
}

void	ft_parses_map2(int i, int j, t_plr *dote)
{
	t_map obj[dote->place_two];
	obj[dote->place_two].x = j + 0.5;
	obj[dote->place_two].y = i + 0.5;
}

void	ft_parses_map(int i, int j, char sym, t_all *len)
{

	if ((sym == 'W'  || sym == 'N' || sym == 'E' || sym == 'S'))
	{
		direction_player(sym, len);
		len->plr.x = j + 0.5;
		len->plr.y = i + 0.5;
		len->plr.flag = len->plr.flag + 1;
	}
	if (len->plr.flag == 1)
	{
		printf("error");
		return ;
	}
	if (sym == '2')
	{
		len->plr.place_two++;
	}
	//printf("%f", len->plr->y);
	//printf("%d", app.place_two);
	//printf("%c\n", *map[0]);
}

char	*ft_spacex(char *line, int max)
{
	int		size;
	char	*str;
	int i;

	i = 0;
	str = NULL;
	size = ft_strlen(line);
	str = (char *)malloc(1 + max);
	ft_memcpy(str, line, size);
	while (size < max)
	{
		str[size] = ' ';
		size++;
	}
	str[max] = '\0';
	return (str);
}

char	**make_map(t_list **head, int size, t_all *len, int max)
{
	//char	**map;
	int		i;
	int		j;
	char	sym;
	char	*line;
	//t_plr	plr;
	t_list	*tmp;

	len->map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	j = -1;
	tmp = *head;
	len->plr.flag = -1;
	len->plr.place_two = 0;
	while (tmp)
	{
		line = tmp->content;
		line = ft_spacex(line, max);
		len->map[++i] = line;
		tmp = tmp->next;
		len->y = i;
	}
	i = -1;
	while (++i < len->y)
	{
		while (++j < ft_strlen(len->map[i]))
		{
			sym = len->map[i][j];
			if (!(ft_strrchr(OBJ, sym)))
			{
				printf("error");//ошибка
				//printf("|%c|", sym);
				break ;
			}
			if (ft_strrchr(OBJJ, sym))
			{
				//printf("|%c|", sym);
				(((len->map[i - 1][j] != ' ') && (len->map[i + 1][j] != ' ')
				&& (len->map[i][j + 1] != ' ') && (len->map[i][j - 1] != ' '))
				? ft_parses_map(i, j, len->map[i][j], len) : printf("error"));
				//printf("%f, %f", dot.x, dot.y);
			}

		}
		//printf("|%s|\n", len->map[i]);
		//printf("\n");
		j = -1;
			//ft_putendl_fd(map[i]);
	}
	i = -1;
	j = -1;
	while (++i < len->y)
	{
		while (++j < ft_strlen(len->map[i]))
		{
			sym = len->map[i][j];
			if (ft_strrchr("2", sym))
			{
				//ft_parses_map2(i, j, &plr);
			}
		}
		j = -1;
	}
	//printf("%f", len->plr.y);
	return (len->map);
}

void	ft_parses(char *map, t_all *len)
{
	t_win	m_mlx;
	t_all	znach;
	char	*str;
	t_imgno	m_img;
	t_imgso	mso_img;
	t_imgwe mwe_img;
	t_imgea mea_img;
	t_imgs ms_img;
	t_colors f_colors;

	mlx_get_screen_size(m_mlx.mlx, &znach.w_width, &znach.w_height);
	// printf("%c\n", *map);
	// printf("%d", len->len_r);
	if (*map == 'R' && len->len_r == -1)
	{
		len->len_r = 1;
		len->sum = len->len_r;
		map++;
		znach.width = ft_atoi(map);
		str = ft_itoa(znach.width);
		while (*str != '\0')
		{
			map++;
			str++;
		}
		map++;
		znach.height = ft_atoi(map);
		if (znach.width < 1 || znach.height < 1)
			return ;// тут ошибку надо написать
		((znach.w_width < znach.width) ? znach.width = znach.w_width
		: znach.width);
		((znach.w_height < znach.height) ? znach.height = znach.w_height
		: znach.height);
		//  printf("1!!!!!!!!!!!!\n");
		//printf("%d____%d", znach.width, znach.height);
	}

	else if ((*map == 'N' && *(map + 1) == 'O') && len->len_no == -1)
	{
		len->len_no = 1;
		len->sum = len->sum + len->len_no;
		map = map + 2;
		znach.textur_no = *ft_split(map, ' ');
		if (!(m_img.no_img = mlx_xpm_file_to_image(m_mlx.mlx,
		znach.textur_no, &m_img.img_wno, &m_img.img_hno)))
			return ;//ошибка какая-то
		m_img.no_addr = mlx_get_data_addr(m_img.no_img,
		&m_img.bits_per_pixel, &m_img.line_length, &m_img.endian);
		//printf("2!!!!!!!!!!!!\n");
	}
	else if ((*map == 'S' && *(map + 1) == 'O') && len->len_so == -1)
	{
		len->len_so = 1;
		len->sum = len->sum + len->len_so;
		map = map + 2;
		znach.textur_so = *ft_split(map, ' ');
		if (!(mso_img.so_img = mlx_xpm_file_to_image(m_mlx.mlx,
		znach.textur_no, &mso_img.img_wso, &mso_img.img_hso)))
			return ;//ошибка какая-то
		mso_img.so_addr = mlx_get_data_addr(mso_img.so_img,
		&mso_img.bits_per_pixel, &mso_img.line_length, &mso_img.endian);
		//printf("3!!!!!!!!!!!!\n");
	}
	else if (*map == 'W' && *(map + 1) == 'E')
	{
		if (len->len_we != -1)
			return ; // ошибка
		len->len_we = 1;
		len->sum = len->sum + len->len_we;
		map = map + 2;
		znach.textur_we = *ft_split(map, ' ');
		if (!(mwe_img.we_img = mlx_xpm_file_to_image(m_mlx.mlx,
		znach.textur_no, &mwe_img.img_wwe, &mwe_img.img_hwe)))
			return ;//ошибка какая-то
		mwe_img.we_addr = mlx_get_data_addr(mwe_img.we_img,
		&mwe_img.bits_per_pixel, &mwe_img.line_length, &mwe_img.endian);
		//printf("4!!!!!!!!!!!!\n");
	}
	else if (*map == 'E' && *(map + 1) == 'A')
	{
		if (len->len_ea != -1)
			return ;// ошибка
		len->len_ea = 1;
		len->sum = len->sum + len->len_ea;
		map = map + 2;
		znach.textur_ea = *ft_split(map, ' ');
		if (!(mea_img.ea_img = mlx_xpm_file_to_image(m_mlx.mlx,
		znach.textur_no, &mea_img.img_wea, &mea_img.img_hea)))
			return ;//ошибка какая-то
		mea_img.ea_addr = mlx_get_data_addr(mea_img.ea_img,
		&mea_img.bits_per_pixel, &mea_img.line_length, &mea_img.endian);
		//printf("5!!!!!!!!!!!!\n");
	}
	else if (*map == 'S')
	{
		if (len->len_s != -1)
			return ; // ошибка
		len->len_s = 1;
		len->sum = len->sum + len->len_s;
		map++;
		znach.textur_s = *ft_split(map, ' ');
		if (!(ms_img.s_img = mlx_xpm_file_to_image(m_mlx.mlx,
		znach.textur_no, &ms_img.img_ws, &ms_img.img_hs)))
			return ;//ошибка какая-то
		ms_img.s_addr = mlx_get_data_addr(ms_img.s_img,
		&ms_img.bits_per_pixel, &ms_img.line_length, &ms_img.endian);
		//printf("6!!!!!!!!!!!!\n");
	}
	else if (*map == 'F')
	{
		if (len->len_f != -1)
			return ; //ошибка
		len->len_f = 1;
		len->sum = len->sum + len->len_f;
		map++;
		f_colors.fbits_one = ft_atoi(map);
		str = ft_strchr(map, ',');
		map = str;
		//printf("1@@@%s\n", map);
		map++;
		f_colors.fbits_two = ft_atoi(map);
		str = ft_strchr(map, ',');
		map = str;
		//printf("1@@@%s\n", map);
		map++;
		f_colors.fbits_three = ft_atoi(map);
		str = "";
		str = ft_strchr(map, ',');
		if (str != '\0')
			return ;//ошибка
		if (f_colors.fbits_one > 255 ||
		f_colors.fbits_two > 255 || f_colors.fbits_three > 255)
			return ;// ошибка
		if (f_colors.fbits_one < 0 ||
		f_colors.fbits_two < 0 || f_colors.fbits_three < 0)
			return ;//ошибка
		ft_colorf(&f_colors);
	// 	printf("7!!!!!!!!!!!!\n");
	// 	printf("%d\n", f_colors.fbits_one);
	// 	printf("%d\n", f_colors.fbits_two);
	// 	printf("%d\n", f_colors.fbits_three);
	 }
	else if (*map == 'C')
	{
		if (len->len_c != -1)
			return ;//ошибка
		len->len_c = 1;
		len->sum = len->sum + len->len_f;
		map++;
		f_colors.cbits_one = ft_atoi(map);
		str = ft_strchr(map, ',');
		map = str;
		//printf("1@@@%s\n", map);
		map++;
		f_colors.cbits_two = ft_atoi(map);
		str = ft_strchr(map, ',');
		map = str;
		//printf("1@@@%s\n", map);
		map++;
		f_colors.cbits_three = ft_atoi(map);
		str = "";
		str = ft_strchr(map, ',');
		if (str != '\0')
			return ;//ошибка
		if (f_colors.cbits_one > 255 ||
		f_colors.cbits_two > 255 || f_colors.cbits_three > 255)
			return ;// ошибка
		if (f_colors.cbits_one < 0 ||
		f_colors.cbits_two < 0 || f_colors.cbits_three < 0)
			return ;//ошибка
		ft_colorc(&f_colors);
	}

	else if (len->sum == 8 /*&& (*map == '1' || *map == ' ')*/)
	{
		str = NULL;
		if (*map == ' ')
		{
			while (*map != '\0')
			{
				if (*map == '1')
				{
					len->flag = 1;
					break ;
				}
				map++;
			}
		}
		if (*map == '1')
		{
			len->flag = 1;
		}
	}

	//printf("%d\n", len->flag);
	// else if (len->sum > 8)
	// {
	// 	exit(1);
	// }
}



// int make_player()
// {
// 	t_plr plr;
// 	plr.x = 22;
// 	plr.y = 12;
// 	plr.dirx = -1;
// 	plr.diry = 0;
// }

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		key(int keycode, t_all *all)
{
	printf("%f\n", all->plr.y);
	int j = 2;
	int x = 5;
	//all->y;
	//mlx_destroy_window(m_mlx->mlx, m_mlx->win);

	if (keycode == 13)
	{
		all->plr.y = all->plr.y - 0.1;
	}
	my_mlx_pixel_put(all->win.mlx, j, all->plr.y, 0x000FF00);
	//printf("%s", all->map[2]);
	return (0);
}



void draw_map(t_all *map, t_list *head)
{

	t_win m_mlx;
	int j;
	int x;

	j = -1;
	x = -1;
	m_mlx.mlx = mlx_init();
	m_mlx.win = mlx_new_window(m_mlx.mlx, 1920, 1080, "cub3D");
	m_mlx.img = mlx_new_image(m_mlx.mlx, 1920, 1080);
	m_mlx.addr = mlx_get_data_addr(m_mlx.img,
	&m_mlx.bpp, &m_mlx.line_l, &m_mlx.en);

	while (++x < (map->y + 1) * 16)
	{

		while (++j < ft_strlen(map->map[x / 16]) * 16)
		{
			if (map->map[x / 16][j / 16] == '1')
			{
				my_mlx_pixel_put(&m_mlx, j, x, 0x00FF0000);
			}
			if (map->map[x / 16][j / 16] == 'N')
			{
				my_mlx_pixel_put(&m_mlx, j, x, 0x000FF00);
				mlx_hook(m_mlx.win, 2, 1L << 0, key, map);
			}
		}
		//printf("%s", map->map[x/16]);
		//printf("\n");
		j = -1;
	}
	//printf("@%s", map->map[x/16]);
	//printf("\n");
	mlx_put_image_to_window(m_mlx.mlx, m_mlx.win, m_mlx.img, 0, 0);
	mlx_loop(m_mlx.mlx);

}

int		main(int argc, char **argv)
{
	//t_win	m_mlx;
	t_all	len;
	t_plr plr;
	int max;

	max = 0;
	len.flag = 0;
	len.len_r = -1;
	len.len_we = -1;
	len.len_no = -1;
	len.len_ea = -1;
	len.len_s = -1;
	len.len_so = -1;
	len.len_c = -1;
	len.len_f = -1;
	len.fd = open(argv[1], O_RDONLY);
	char	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(len.fd, &line))
	{
		len.str_first = line;
		ft_parses(line, &len);
		if (len.flag == 1)
			break ;
	}
	if (len.flag == 0)
		printf("error");
	if (ft_strlen(len.str_first) > max)
		max = ft_strlen(len.str_first);
	ft_lstadd_front(&head, ft_lstnew(len.str_first));
	while (get_next_line(len.fd, &line))
	{
		if (ft_strlen(line) > max)
			max = ft_strlen(line);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	make_map(&head, ft_lstsize(head), &len, max);
	//printf("%f", len.plr.y);
	draw_map(&len, head);

	//make_player();
}
