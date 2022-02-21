#include "libft.h"

char	*ft_strchr(const char *str, int ch)
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
