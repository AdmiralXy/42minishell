#include "ft_minishell.h"

int	ft_find_flags_length(const char *str, int i)
{
	int	k;
	int result;
	int	onFlag;

	k = 1;
	result = 0;
	onFlag = 1;
	while (str[i - 1] != '\0')
	{
		if (onFlag && (str[i] == ' ' || str[i] == '\t' || str[i] == '\0'
			|| str[i] == '|'))
		{
			onFlag = 0;
			result = k - 1;
		}
		if (!onFlag && str[i] == '-' && (str[i + 1] && str[i + 1] != ' '
										 && str[i + 1] != '\t'))
			onFlag = 1;
		if (!onFlag && str[i] != '-' && str[i] != ' ' && str[i] != '\t')
			return (result);
		k++;
		i++;
	}
	return (result);
}

int	ft_next_redir(const char *input, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else if (input[i] == '<' || input[i] == '>')
			return (i);
		else
			return (0);
	}
	while (i <= end)
	{
		if (input[i] == '<' || input[i] == '>')
			return (i);
		else if (input[i] != ' ' && input[i] != '\t')
			return (0);
		i++;
	}
	return (0);
}

int	ft_args_end(const char *input, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if ((input[i] == ' ' || input[i] == '\t') && (input[i + 1] == '>'
				|| input[i + 1] == '<' || input[i + 1] == '|'
					|| input[i + 1] == '\0'))
			return (i);
		i++;
	}
	return (i);
}
