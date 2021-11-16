#include "ft_minishell.h"

t_node	*ft_node_create(void)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->next = NULL;
	new->redirs = NULL;
	new->command = NULL;
	new->flags = NULL;
	new->args = NULL;
	new->c_end = '\0';
	new->redir_0 = 0;
	new->redir_1 = 1;
	return (new);
}

t_redir	*ft_node_redir_create(void)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (0);
	new->next = NULL;
	new->type = 0;
	new->value = NULL;
	return (new);
}

void	*ft_list_create_back(void **lst, void *new)
{
	t_node	*iter;

	if (*lst != 0)
	{
		iter = *lst;
		while (iter->next != 0)
		{
			iter = iter->next;
		}
		iter->next = new;
		return (iter->next);
	}
	else
		*lst = new;
	return (*lst);
}
