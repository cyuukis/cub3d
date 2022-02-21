#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	str = s;
	i = 0;
	while (n)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}
