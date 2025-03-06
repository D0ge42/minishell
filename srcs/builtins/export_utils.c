#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[0]))
			return (0);
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	value_checker(char **sorted_exp, int i)
{
	char	*tmp;
	int		eq_index;

	eq_index = 0;
	while (sorted_exp[i][eq_index] && sorted_exp[i][eq_index] != '=')
		eq_index++;
	if (sorted_exp[i][eq_index] == '=' && sorted_exp[i][eq_index + 1] == '\0')
	{
		tmp = sorted_exp[i];
		sorted_exp[i] = ft_strjoin(sorted_exp[i], "\"\"");
		if (!sorted_exp[i])
			return ;
		free(tmp);
	}
}

char	*strdup_and_add_quotes(char *str)
{
	int		i;
	int		j;
	char	*new;

	new = ft_calloc(ft_strlen(str) + 3, 1);
	if (!new)
	{
		print_error(ERR_MALLOC);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str + j != ft_strchr(str, '=') && str[j])
		new[i++] = str[j++];
	if (ft_strchr(str, '='))
	{
		new[i++] = '=';
		j++;
		new[i++] = '"';
		while (str[j])
			new[i++] = str[j++];
		new[i++] = '"';
	}
	return (new);
}

char	**export_strsdup(char **strs)
{
	int		i;
	int		quantity;
	char	**new_env;

	i = 0;
	quantity = ft_strslen(strs);
	new_env = ft_calloc(quantity + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	while (strs[i])
	{
		new_env[i] = strdup_and_add_quotes(strs[i]);
		if (!new_env[i])
		{
			ft_free_strs(strs);
			print_error(ERR_MALLOC);
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

int	check_var_existence(char **env, char *ptr)
{
	int	i;
	int	equal_index;
	int	j;

	i = 0;
	while (ptr[i] && ptr[i] != '=')
		i++;
	equal_index = i;
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (!ft_strncmp(env[i], ptr, ft_maxint(j, equal_index)))
			return (i);
		i++;
	}
	return (-1);
}
