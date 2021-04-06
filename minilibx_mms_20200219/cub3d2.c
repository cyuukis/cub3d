/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:57:40 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/06 22:36:31 by cyuuki           ###   ########.fr       */
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

// void	ft_colorf(t_all *all)
// {
// 	int r;
// 	int g;
// 	int b;

// 	r = all->colors.fbits_one << 1;
// 	g = all->colors.fbits_two << 8;
// 	b = all->colors.fbits_three << 0;
// 	all->colors.fbits_color = r | g | b;
// }

// void	ft_colorc(t_all *all)
// {
// 	int r;
// 	int g;
// 	int b;

// 	r = all->colors.cbits_one << 1;
// 	g = all->colors.cbits_two << 8;
// 	b = all->colors.cbits_three << 0;
// 	all->colors.cbits_color = r | g | b;
// }

// char	*ft_spacex(char *line, int max)
// {
// 	int		size;
// 	char	*str;

// 	str = NULL;
// 	size = ft_strlen(line);
// 	str = (char *)malloc(1 + max);
// 	ft_memcpy(str, line, size);
// 	while (size < max)
// 	{
// 		str[size] = ' ';
// 		size++;
// 	}
// 	str[max] = '\0';
// 	return (str);
// }

// void	direction_player(char sym, t_all *dote)
// {
// 	if (sym == 'N')
// 	{
// 		dote->plr.direction = 3 * M_PI_2;
// 	}
// 	if (sym == 'S')
// 	{
// 		dote->plr.direction = M_PI_2;
// 	}
// 	if (sym == 'W')
// 	{
// 		dote->plr.direction = M_PI;
// 	}
// 	if (sym == 'E')
// 	{
// 		dote->plr.direction = 0;
// 	}
// }

// void	ft_parses_map2(int y, int x, t_all *all)
// {
// 	static	int		count;
// 	float			dx;
// 	float			dy;

// 	all->obj[count].x = x + 0.5;
// 	all->obj[count].y = y + 0.5;
// 	count++;
// 	all->count = count;
// }

// void	ft_parses_map(int i, int j, char sym, t_all *len)
// {
// 	if ((sym == 'W' || sym == 'N' || sym == 'E' || sym == 'S'))
// 	{
// 		direction_player(sym, len);
// 		len->plr.x = j + 0.5;
// 		len->plr.y = i + 0.5;
// 		len->plr.flag = len->plr.flag + 1;
// 	}
// 	if (len->plr.flag == 1)
// 	{
// 		printf("error");
// 		return ;
// 	}
// 	if (sym == '2')
// 	{
// 		len->plr.place_two++;
// 	}
// }

// void	make_map3(t_all *len)
// {
// 	int		i;
// 	int		j;
// 	char	sym;

// 	i = -1;
// 	j = -1;
// 	len->obj = (t_map *)malloc(sizeof(t_map) * len->plr.place_two);
// 	while (++i < len->y)
// 	{
// 		while (++j < ft_strlen(len->map[i]))
// 		{
// 			sym = len->map[i][j];
// 			if (ft_strrchr("2", sym))
// 			{

// 				ft_parses_map2(i, j, len);
// 			}
// 		}
// 		j = -1;
// 	}
// }

// void	make_map2(t_all *len)
// {
// 	int		i;
// 	int		j;
// 	char	sym;

// 	j = -1;
// 	i = -1;
// 	while (++i < len->y)
// 	{
// 		while (++j < ft_strlen(len->map[i]))
// 		{
// 			sym = len->map[i][j];
// 			if (!(ft_strrchr(OBJ, sym)))
// 			{
// 				printf("error");//ошибка
// 				break ;
// 			}
// 			if (ft_strrchr(OBJJ, sym))
// 				(((len->map[i - 1][j] != ' ') && (len->map[i + 1][j] != ' ')
// 				&& (len->map[i][j + 1] != ' ') && (len->map[i][j - 1] != ' '))
// 				? ft_parses_map(i, j, len->map[i][j], len) : printf("error"));
// 		}
// 		j = -1;
// 	}
// 	make_map3(len);
// }

// char	**make_map(t_list **head, int size, t_all *len, int max)
// {
// 	int		i;
// 	int		j;
// 	char	sym;
// 	char	*line;
// 	t_list	*tmp;

// 	len->map = ft_calloc(size + 1, sizeof(char *));
// 	i = -1;
// 	j = -1;
// 	tmp = *head;
// 	while (tmp)
// 	{
// 		line = tmp->content;
// 		line = ft_spacex(line, max);
// 		len->map[++i] = line;
// 		tmp = tmp->next;
// 		len->y = i;
// 	}
// 	make_map2(len);
// 	return (len->map);
// }

// void	ft_parser_r(t_all *len, char *map)
// {
// 	char *str;

// 	len->len_r = 1;
// 	len->sum = len->len_r;
// 	map++;
// 	len->width = ft_atoi(map);
// 	str = ft_itoa(len->width);
// 	while (*str != '\0')
// 	{
// 		map++;
// 		str++;
// 	}
// 	map++;
// 	len->height = ft_atoi(map);
// 	if (len->width < 1 || len->height < 1)
// 		return ;// тут ошибку надо написать
// 	((len->w_width < len->width) ? len->width = len->w_width
// 	: len->width);
// 	((len->w_height < len->height) ? len->height = len->w_height
// 	: len->height);
// }

// void	ft_parser_no(t_all *len, char *map)
// {
// 	len->len_no = 1;
// 	len->sum = len->sum + len->len_no;
// 	map = map + 2;
// 	len->textur_no = *ft_split(map, ' ');
// 	printf("|%s|\n", len->textur_no);
// 	if (!(len->imgno.img = mlx_xpm_file_to_image(len->win.mlx,
// 	len->textur_no, &len->imgno.img_w, &len->imgno.img_h)))
// 		printf("%s\n", len->imgno.img);//return ;//ошибка какая-то
// 	len->imgno.addr = mlx_get_data_addr(len->imgno.img,
// 	&len->imgno.bpp, &len->imgno.line_l, &len->imgno.en);
// }

// void	ft_parser_so(t_all *len, char *map)
// {
// 	len->len_so = 1;
// 	len->sum = len->sum + len->len_so;
// 	map = map + 2;
// 	len->textur_so = *ft_split(map, ' ');
// 	if (!(len->imgso.img = mlx_xpm_file_to_image(len->win.mlx,
// 	len->textur_so, &len->imgso.img_w, &len->imgso.img_h)))
// 		return ;//ошибка какая-то
// 	len->imgso.addr = mlx_get_data_addr(len->imgso.img,
// 	&len->imgso.bpp, &len->imgso.line_l, &len->imgso.en);
// }

// void	ft_parser_we(t_all *len, char *map)
// {
// 	if (len->len_we != -1)
// 		return ; // ошибка
// 	len->len_we = 1;
// 	len->sum = len->sum + len->len_we;
// 	map = map + 2;
// 	len->textur_we = *ft_split(map, ' ');
// 	if (!(len->imgwe.img = mlx_xpm_file_to_image(len->win.mlx,
// 	len->textur_we, &len->imgwe.img_w, &len->imgwe.img_h)))
// 		return ;//ошибка какая-то
// 	len->imgwe.addr = mlx_get_data_addr(len->imgwe.img,
// 	&len->imgwe.bpp, &len->imgwe.line_l, &len->imgwe.en);
// }

// void	ft_parser_ea(t_all *len, char *map)
// {
// 	if (len->len_ea != -1)
// 		return ;// ошибка
// 	len->len_ea = 1;
// 	len->sum = len->sum + len->len_ea;
// 	map = map + 2;
// 	len->textur_ea = *ft_split(map, ' ');
// 	if (!(len->imgea.img = mlx_xpm_file_to_image(len->win.mlx,
// 	len->textur_ea, &len->imgea.img_w, &len->imgea.img_h)))
// 		return ;//ошибка какая-то
// 	len->imgea.addr = mlx_get_data_addr(len->imgea.img,
// 	&len->imgea.bpp, &len->imgea.line_l, &len->imgea.en);
// }

// void	ft_parser_s(t_all *len, char *map)
// {
// 	if (len->len_s != -1)
// 		return ; // ошибка
// 	len->len_s = 1;
// 	len->sum = len->sum + len->len_s;
// 	map++;
// 	len->textur_s = *ft_split(map, ' ');
// 	if (!(len->imgs.img = mlx_xpm_file_to_image(len->win.mlx,
// 	len->textur_s, &len->imgs.img_w, &len->imgs.img_h)))
// 		return ;//ошибка какая-то
// 	len->imgs.addr = mlx_get_data_addr(len->imgs.img,
// 	&len->imgs.bpp, &len->imgs.line_l, &len->imgs.en);
// }

// void	ft_fpars(t_all *len)
// {
// 	if (len->colors.fbits_one > 255 ||
// 	len->colors.fbits_two > 255 || len->colors.fbits_three > 255)
// 		return ;// ошибка
// 	if (len->colors.fbits_one < 0 ||
// 	len->colors.fbits_two < 0 || len->colors.fbits_three < 0)
// 		return ;//ошибка
// }

// void	ft_parser_f(t_all *len, char *map)
// {
// 	char *str;

// 	if (len->len_f != -1)
// 		return ; //ошибка
// 	len->len_f = 1;
// 	len->sum = len->sum + len->len_f;
// 	map++;
// 	len->colors.fbits_one = ft_atoi(map);
// 	str = ft_strchr(map, ',');
// 	map = str;
// 	map++;
// 	len->colors.fbits_two = ft_atoi(map);
// 	str = ft_strchr(map, ',');
// 	map = str;
// 	map++;
// 	len->colors.fbits_three = ft_atoi(map);
// 	str = "";
// 	str = ft_strchr(map, ',');
// 	if (str != '\0')
// 		return ;//ошибка
// 	ft_fpars(len);
// 	ft_colorf(len);
// }

// void	ft_cpars(t_all *len)
// {
// 	if (len->colors.cbits_one > 255 ||
// 	len->colors.cbits_two > 255 || len->colors.cbits_three > 255)
// 		return ;// ошибка
// 	if (len->colors.cbits_one < 0 ||
// 	len->colors.cbits_two < 0 || len->colors.cbits_three < 0)
// 		return ;//ошибка
// }

// void	ft_parser_c(t_all *len, char *map)
// {
// 	char *str;

// 	if (len->len_c != -1)
// 		return ;//ошибка
// 	len->len_c = 1;
// 	len->sum = len->sum + len->len_f;
// 	map++;
// 	len->colors.cbits_one = ft_atoi(map);
// 	str = ft_strchr(map, ',');
// 	map = str;
// 	map++;
// 	len->colors.cbits_two = ft_atoi(map);
// 	str = ft_strchr(map, ',');
// 	map = str;
// 	map++;
// 	len->colors.cbits_three = ft_atoi(map);
// 	str = "";
// 	str = ft_strchr(map, ',');
// 	if (str != '\0')
// 		return ;//ошибка
// 	ft_cpars(len);
// 	ft_colorc(len);
// }

// void	ft_parser_map(t_all *len, char *map)
// {
// 	char *str;

// 	str = NULL;
// 	if (*map == ' ')
// 	{
// 		while (*map != '\0')
// 		{
// 			if (*map == '1')
// 			{
// 				len->flag = 1;
// 				break ;
// 			}
// 			map++;
// 		}
// 	}
// 	if (*map == '1')
// 		len->flag = 1;
// }

// void	ft_parses(char *map, t_all *len)
// {
// 	mlx_get_screen_size(len->win.mlx, &len->w_width, &len->w_height);
// 	if (*map == 'R' && len->len_r == -1)
// 		ft_parser_r(len, map);
// 	else if ((*map == 'N' && *(map + 1) == 'O') && len->len_no == -1)
// 		ft_parser_no(len, map);
// 	else if ((*map == 'S' && *(map + 1) == 'O') && len->len_so == -1)
// 		ft_parser_so(len, map);
// 	else if (*map == 'W' && *(map + 1) == 'E')
// 		ft_parser_we(len, map);
// 	else if (*map == 'E' && *(map + 1) == 'A')
// 		ft_parser_ea(len, map);
// 	else if (*map == 'S')
// 		ft_parser_s(len, map);
// 	else if (*map == 'F')
// 		ft_parser_f(len, map);
// 	else if (*map == 'C')
// 		ft_parser_c(len, map);
// 	else if (len->sum == 8 /*&& (*map == '1' || *map == ' ')*/)
// 		ft_parser_map(len, map);
// 	//printf("%d\n", len->flag);
// 	// else if (len->sum > 8)
// 	// {
// 	// 	exit(1);
// 	// }
// }

void	ft_col(int max, t_all *len, t_list *head, char *line)
{
	while (get_next_line(len->fd, &line))
	{
		if (ft_strlen(line) > max)
			max = ft_strlen(line);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
}

void	ft_param(t_all *len)
{
	len->flag = 0;
	len->len_r = -1;
	len->len_we = -1;
	len->len_no = -1;
	len->len_ea = -1;
	len->len_s = -1;
	len->len_so = -1;
	len->len_c = -1;
	len->len_f = -1;
	len->plr.place_two = 0;
}

int		main(int argc, char **argv)
{
	t_list	*head;
	t_all	len;
	int		max;
	char	*line;

	len.win.mlx = mlx_init();
	ft_param(&len);
	len.fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
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
	ft_col(max, &len, head, line);
	make_map(&head, ft_lstsize(head), &len, max);
	draw_map(&len);
}
