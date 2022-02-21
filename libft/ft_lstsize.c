#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				i;
	struct s_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
