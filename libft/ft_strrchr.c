#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	l;

	l = ft_strlen((char *)str) + 1;
	while (l--)
	{
		if ((unsigned char)*(str + l) == (unsigned char)ch)
			return ((char *)(str + l));
	}
	return (NULL);
}
