#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return ((char *)dest);
}
