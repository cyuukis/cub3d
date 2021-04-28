/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:44:58 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/28 15:43:38 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"

static void	new_param(t_all *len, char *argv)
{
	len->win.mlx = mlx_init();
	ft_param(len);
	len->fd = open(argv, O_RDONLY);
	if (len->fd == -1)
		exit_error();
}

static void	new_parser(t_all *len, char *line)
{
	while (get_next_line(len->fd, &line))
	{
		if(*line != '\0')
		{
			len->str_first = line;
			ft_parses(line, len);
		}
		else
			free(line);
		if (len->flag == 1)
			break ;
	}
	if (len->flag == 0)
		exit_error();
}

static char	*prs(t_all *len, char *argv, char *line)
{
	new_param(len, argv);
	new_parser(len, line);
	if (len->flag == 0)
		exit_error();
	return (line);
}

static void	exit_ee(int argc)
{
	if (argc == 1)
		exit_error();
}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_all	len;
	int		max;
	char	*line;

	exit_ee(argc);
	max = ft_strlen(&argv[1][0]);
	line = ft_strdup(&argv[1][0]);
	if (argc >= 2 && argc <= 3)
	{
		if (ft_strncmp(&line[max - 4], ".cub", 5) == 0)
		{
			free(line);
			max = 0;
			head = NULL;
			line = prs(&len, argv[1], line);
			printf("|%s|\n", line);
			if (ft_strlen(len.str_first) > max)
				max = ft_strlen(len.str_first) + 1;
			maping(&len, head, max, line);
			draw_map(&len, argc, argv[2]);
			close(len.fd);
		}
		else
			exit_error();
	}
}
