#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	z;

	i = 0;
	n = -1;
	z = 1;
	if (str[i] == ' ' || str[i] == ',' || \
	(str[i] >= '0' && str[i] <= '9') || str[i] == '\0')
	{
		while ((str[i] >= '\t' && str[i] <= '\r') \
		|| str[i] == ' ' || str[i] == ',')
		{
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (n == -1)
				n = 0;
			n = 10 * n + (str[i] - '0');
			i++;
		}
		return (z * n);
	}
	return (-1);
}
