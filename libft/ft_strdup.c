#include "libft.h"

char	*ft_strdup(const char *str)
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
