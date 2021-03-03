/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuuki <cyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:33:13 by cyuuki            #+#    #+#             */
/*   Updated: 2021/01/15 18:01:59 by cyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	str -= len;
	return (str);
}

char				*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			str2 = (char *)&str[i];
			return (str2);
		}
		i++;
	}
	if (str[i] == ch)
	{
		str2 = (char *)&str[i];
		return (str2);
	}
	return (NULL);
}

char				*ft_strdup(const char *str)
{
	char	*string;
	size_t	i;

	i = 0;
	i = ft_strlen(str);
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
