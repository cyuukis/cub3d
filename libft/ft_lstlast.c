#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	struct s_list	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
