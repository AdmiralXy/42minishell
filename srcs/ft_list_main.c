#include "ft_minishell.h"

void	ft_build_cmds(t_node **cmds, char *input)
{
	int		i;
	int		j;
	int		in_qts;

	i = 0;
	j = 0;
	in_qts = 0;
	while (i - 1 < 0 || input[i - 1] != '\0')
	{
		if (input[i] == STRING_QUOTE)
			in_qts = !in_qts;
		if (!in_qts && ft_is_split(input, i))
			ft_list_create_back((void **)cmds, ft_build_cmd(input, &j, &i));
		i++;
	}
}
