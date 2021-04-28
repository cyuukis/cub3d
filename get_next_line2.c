/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:22:18 by cyuuki            #+#    #+#             */
/*   Updated: 2021/04/28 13:42:16 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	add_check2(char **choto, char *temp)
{
	if (!(*choto))
		return (-1);
	if (temp)
		free(temp);
	return (0);
}

int	add_check3(char **choto, char *temp)
{
	if (!(*choto))
		return (-1);
	if (temp)
		free(temp);
	return (1);
}
