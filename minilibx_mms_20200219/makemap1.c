/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:32:04 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/06 22:34:02 by cyuuki           ###   ########.fr       */
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

void	ft_parses_map(int i, int j, char sym, t_all *len)
{
	if ((sym == 'W' || sym == 'N' || sym == 'E' || sym == 'S'))
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
}

void	make_map3(t_all *len)
{
	int		i;
	int		j;
	char	sym;

	i = -1;
	j = -1;
	len->obj = (t_map *)malloc(sizeof(t_map) * len->plr.place_two);
	while (++i < len->y)
	{
		while (++j < ft_strlen(len->map[i]))
		{
			sym = len->map[i][j];
			if (ft_strrchr("2", sym))
			{

				ft_parses_map2(i, j, len);
			}
		}
		j = -1;
	}
}

void	make_map2(t_all *len)
{
	int		i;
	int		j;
	char	sym;

	j = -1;
	i = -1;
	while (++i < len->y)
	{
		while (++j < ft_strlen(len->map[i]))
		{
			sym = len->map[i][j];
			if (!(ft_strrchr(OBJ, sym)))
			{
				printf("error");//ошибка
				break ;
			}
			if (ft_strrchr(OBJJ, sym))
				(((len->map[i - 1][j] != ' ') && (len->map[i + 1][j] != ' ')
				&& (len->map[i][j + 1] != ' ') && (len->map[i][j - 1] != ' '))
				? ft_parses_map(i, j, len->map[i][j], len) : printf("error"));
		}
		j = -1;
	}
	make_map3(len);
}

char	*ft_spacex(char *line, int max)
{
	int		size;
	char	*str;

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
	int		i;
	int		j;
	char	sym;
	char	*line;
	t_list	*tmp;

	len->map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	j = -1;
	tmp = *head;
	while (tmp)
	{
		line = tmp->content;
		line = ft_spacex(line, max);
		len->map[++i] = line;
		tmp = tmp->next;
		len->y = i;
	}
	make_map2(len);
	return (len->map);
}
