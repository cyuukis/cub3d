/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:55:41 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/28 15:45:15 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

static char	*ft_spacex(char *line, int max)
{
	int		size;
	char	*str;

	str = NULL;
	size = ft_strlen(line);
	str = (char *)malloc(1 + max);
	if (str == NULL)
		exit_error();
	ft_memcpy(str, line, size);
	while (size < max)
	{
		str[size] = ' ';
		size++;
	}
	str[max] = '\0';
	return (str);
}

static void	make_map2(t_all *len)
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
				exit_error();
			if (ft_strrchr(OBJJ, sym))
				make_map_rectl(len, i, j);
		}
		j = -1;
	}
	if (len->plr.flag != 0)
		exit_error();
	make_map3(len);
}

static char	**make_map(t_list **head, int size, t_all *len, int max)
{
	int		i;
	int		j;
	char	*line;
	t_list	*tmp;

	len->map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	j = -1;
	tmp = *head;
	len->plr.flag = -1;
	len->plr.place_two = 0;
	while (tmp)
	{
		line = ft_spacex(tmp->content, max);
		len->map[++i] = line;
		tmp = tmp->next;
		len->y = i;
	}
	make_map2(len);
	ft_lstclear(head, free);
	len->plr.c = malloc(sizeof(float) * len->width);
	if (len->plr.c == NULL)
		exit_error();
	return (len->map);
}

static void	ft_col(int max, t_all *len, t_list *head, char *line)
{
	while (get_next_line(len->fd, &line))
	{
		if (ft_strlen(line) > max)
			max = ft_strlen(line);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	free(line);
}

void	maping(t_all *len, t_list *head, int max, char *line)
{
	ft_lstadd_front(&head, ft_lstnew(len->str_first));
	ft_col(max, len, head, line);
	make_map(&head, ft_lstsize(head), len, max);
}
