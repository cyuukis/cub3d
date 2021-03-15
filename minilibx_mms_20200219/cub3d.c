/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:33:43 by cyuuki            #+#    #+#             */
/*   Updated: 2021/03/15 23:02:37 by cyuuki           ###   ########.fr       */
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
#define OBJ " 102WESN"
#define OBJJ "02WESN"

void ft_colorf(t_colors *f_colors)
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
void ft_colorc(t_colors *f_colors)
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
void	ft_parses_map(int i, int j, t_plr *dote)
{
	dote->x = j + 0.5;
	dote->y = i + 0.5;
	//printf("%c\n", *map[0]);
}

char	**make_map(t_list **head, int size, t_all *len)
{
	char	**map = ft_calloc(size + 1, sizeof(char *));
	int		i = -1;
	int		j = -1;
	int		x;
	char	sym;
	t_plr dot;

	t_list	*tmp = *head;
	t_all *num;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
		x = i;
	}
	i = -1;
	//printf("%s", OBJ);

	while (++i < x)
	{
		while (++j < ft_strlen(map[i]))
		{
			sym = map[i][j];
			if (!(ft_strrchr(OBJ, sym)))
			{
				printf("error");//ошибка
				break ;
			}
			if (ft_strrchr(OBJJ, sym))
			{
				//printf("%c", sym);
				(((map[i - 1][j] != ' ') && (map[i + 1][j] != ' ') && (map[i][j + 1] != ' ') && (map[i][j - 1] != ' '))
				? ft_parses_map(i, j, &dot) : printf("error"));
				//printf("%f, %f", dot.x, dot.y);
			}
			// if (map[i][j] == 'E')
			// {
			// 	((map[i - 1][j] != ' ' && map[i + 1][j] != ' '
			// 	&& map[i][j + 1] != ' ' && map[i][j - 1] != ' ')
			// 	? ft_parses_map(i, j, &dot) : printf("error"));
			// 	//printf("%f, %f", dot.x, dot.y);
			// }
			// if (map[i][j] == 'S')
			// {
			// 	((map[i - 1][j] != ' ' && map[i + 1][j] != ' '
			// 	&& map[i][j + 1] != ' ' && map[i][j - 1] != ' ')
			// 	? ft_parses_map(i, j, &dot) : printf("error"));
			// 	//printf("%f, %f", dot.x, dot.y);
			// }
			// if (map[i][j] == 'N')
			// {
			// 	((map[i - 1][j] != ' ' && map[i + 1][j] != ' '
			// 	&& map[i][j + 1] != ' ' && map[i][j - 1] != ' ')
			// 	? ft_parses_map(i, j, &dot) : printf("error"));
			// 	//printf("%f, %f", dot.x, dot.y);
			// }
			// if (map[i][j] == '0')
			// {
			// 	((map[i - 1][j] != ' ' && map[i + 1][j] != ' '
			// 	&& map[i][j + 1] != ' ' && map[i][j - 1] != ' ')
			// 	? ft_parses_map(i, j, &dot) : printf("error"));
			// 	//printf("%f, %f", dot.x, dot.y);
			// }
			// if (map[i][j] == '2')
			// {
			// 	((map[i - 1][j] != ' ' && map[i + 1][j] != ' '
			// 	&& map[i][j + 1] != ' ' && map[i][j - 1] != ' ')
			// 	? ft_parses_map(i, j, &dot) : printf("error"));
			// 	//printf("%f, %f", dot.x, dot.y);
			// }
			//printf("%c", map[i][j]);
		}
		//printf("\n");
		j = -1;
			//ft_putendl_fd(map[i]);
	}
	return (map);
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
	else if (len->sum == 8 && *map == '1')
	{
		str = NULL;
		len->flag = 1;
		// while (get_next_line(len->fd, &str))
		// {
		// 	//printf("%s\n", len->fd);
		// 	ft_lstadd_back(&head, ft_lstnew(str));
		// }
		// ft_lstadd_back(&head, ft_lstnew(str));
		// make_map(&head, ft_lstsize(head), len);
		// //return ;
	}
}



// int make_player()
// {
// 	t_plr plr;
// 	plr.x = 22;
// 	plr.y = 12;
// 	plr.dirx = -1;
// 	plr.diry = 0;
// }

int		main(int argc, char **argv)
{
	t_win m_mlx;
	t_all len;

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
	//m_mlx.mlx = mlx_init();
	while (get_next_line(len.fd, &line))
	{
		len.str_first = line;
		ft_parses(line, &len);
		if (len.flag == 1)
			break ;
	}
	ft_lstadd_front(&head, ft_lstnew(len.str_first));
	while (get_next_line(len.fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
		make_map(&head, ft_lstsize(head), &len);
	//make_player();
}
