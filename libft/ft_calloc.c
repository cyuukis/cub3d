#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*s;
	size_t	sum;

	sum = number * size;
	s = (char *)malloc(sum);
	if (!s)
		return (NULL);
	ft_bzero(s, sum);
	return (s);
}
