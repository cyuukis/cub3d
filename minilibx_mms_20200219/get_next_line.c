/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:13:02 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/26 22:32:49 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	add_check_cache(char **cache, char **line)
{
	char	*temp;
	char	*point;

	point = ft_strchr(*cache, '\n');
	if (point)
		*point = '\0';
	temp = *line;
	*line = ft_strjoin(*line, *cache);
	if (!(*line))
		return (-1);
	free(temp);
	temp = NULL;
	if (point != NULL && *(point + 1) != '\0')
	{
		temp = ft_strdup(point + 1);
		if (!(temp))
			return (-1);
	}
	free(*cache);
	*cache = temp;
	if (point)
		return (1);
	else
		return (0);
}

static int	add_check(char *buffer, char **line, char **cache)
{
	char	*point;
	char	*temp;

	if (!buffer)
		return (0);
	point = ft_strchr(buffer, '\n');
	if (point)
	{
		*point = '\0';
		if ((*(++point)) != '\0')
		{
			*cache = ft_strdup(point);
			if (!(*cache))
				return (-1);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		if (!(*line))
			return (-1);
		free(temp);
		return (1);
	}
	temp = *line;
	*line = ft_strjoin(*line, buffer);
	if (!(*line))
		return (-1);
	free(temp);
	return (0);
}

static int	dopfun1(int add, char *cache, char **line)
{
	if (cache)
	{
		add = add_check_cache(&cache, line);
		if (add)
			return (add);
	}
	return (0);
}

static int	dopfun2(int add, char *cache)
{
	if (add == -1)
	{
		free(cache);
		return (-1);
	}
	if (add == 0)
		cache = NULL;
	if (add == 0)
		return (0);
	else
		return (1);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	int				add;
	static char		*cache;

	*line = (char *)malloc(1);
	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line))
		return (-1);
	**line = '\0';
	if (cache)
	{
		add = add_check_cache(&cache, line);
		if (add)
			return (add);
	}
	add = dopfun1(add, cache, line);
	add = read(fd, buffer, BUFFER_SIZE);
	while (add > 0)
	{
		buffer[add] = '\0';
		add = add_check(buffer, line, &cache);
		if (add == 1 || add == -1)
			break ;
	}
	return (dopfun2(add, cache));
}
