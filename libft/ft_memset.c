#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	int		i;
	char	*src;

	src = dest;
	i = 0;
	while (n)
	{
		src[i] = c;
		i++;
		n--;
	}
	return (dest);
}
