/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:33:43 by cyuuki            #+#    #+#             */
/*   Updated: 2021/03/03 22:09:10 by cyuuki           ###   ########.fr       */
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

void	ft_parses(char *map)
{
	t_all	znach;
	t_list	tmp;
	char	*str;
	int		num;

	if (*map == 'R')
	{
		map++;
		znach.width = ft_atoi(map);
		num = znach.width;
		str = ft_itoa(num);
		while (*str != '\0')
		{
			map++;
			str++;
		}
		map++;
		znach.height = ft_atoi(map);
		//printf("%d", znach.height);
	}
	if (*map == 'N' && *(map+1) == 'O')
	{
		map++;

		printf("!!!!!!!!!!!!!!");
	}
}

char	**make_map(t_list **head, int size)
{
	char	**map = ft_calloc(size + 1, sizeof(char *));
	int		i = -1;
	t_list	*tmp = *head;
	t_all *num;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	 while (map[++i])
	{
		ft_parses(map[i]);
		ft_putendl_fd(map[i]);
	}
	return (map);
}

int make_player()
{
	t_plr plr;
	plr.x = 22;
	plr.y = 12;
	plr.dirx = -1;
	plr.diry = 0;
	
}

int		main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDONLY);
	char	*line = NULL;
	t_list	*head = NULL;

	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
	make_player();
}
