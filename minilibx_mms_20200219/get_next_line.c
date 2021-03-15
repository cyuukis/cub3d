/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:13:02 by cyuuki            #+#    #+#             */
/*   Updated: 2021/03/15 18:40:52 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		add_check_cache(char **cache, char **line)
{
	char	*temp;
	char	*point;

	if ((point = ft_strchr(*cache, '\n')))
		*point = '\0';
	temp = *line;
	if (!(*line = ft_strjoin(*line, *cache)))
		return (-1);
	free(temp);
	temp = NULL;
	if (point != NULL && *(point + 1) != '\0')
		if (!(temp = ft_strdup(point + 1)))
			return (-1);
	free(*cache);
	*cache = temp;
	if (point)
		return (1);
	else
		return (0);
}

static int		add_check(char *buffer, char **line, char **cache)
{
	char *point;
	char *temp;

	if (!buffer)
		return (0);
	if ((point = ft_strchr(buffer, '\n')))
	{
		*point = '\0';
		if ((*(++point)) != '\0')
			if (!(*cache = ft_strdup(point)))
				return (-1);
		temp = *line;
		if (!(*line = ft_strjoin(*line, buffer)))
			return (-1);
		free(temp);
		return (1);
	}
	temp = *line;
	if (!(*line = ft_strjoin(*line, buffer)))
		return (-1);
	free(temp);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	int				add;
	static	char	*cache;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	if (cache)
		if ((add = add_check_cache(&cache, line)))
			return (add);
	while ((add = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[add] = '\0';
		add = add_check(buffer, line, &cache);
		if (add == 1 || add == -1)
			break ;
	}
	if (add == -1)
	{
		free(cache);
		return (-1);
	}
	if (add == 0)
		cache = NULL;
	return ((add == 0) ? 0 : 1);
}
