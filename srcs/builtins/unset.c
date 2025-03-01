#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static void	unset_variable(t_data *data, char **new_env, char **to_remove);
static char	**reallocate_env(t_data *data);
static char	**fill_to_remove(t_data *data);

void	custom_unset(t_data *data)
{
	char	**new_env;
	char	**to_remove;

	if (!data->cmd_line[1])
		return ;
	to_remove = fill_to_remove(data);
	new_env = reallocate_env(data);
	if (!new_env)
		return ;
	unset_variable(data, new_env, to_remove);
	free(data->env);
	data->env = new_env;
}

static char	**reallocate_env(t_data *data)
{
	char	**new_env;
	int		i;

	i = 0;
	while (data->env[i])
		i++;
	new_env = ft_calloc(i + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	return (new_env);
}

static char	**fill_to_remove(t_data *data)
{
	int		i;
	char	**to_remove;

	i = 1;
	to_remove = ft_calloc((count_tokens(data->cmd_line) - 1), sizeof(char *));
	if (!to_remove)
		return (NULL);
	while (data->cmd_line[i])
	{
		to_remove[i - 1] = ft_strdup(data->cmd_line[i]->content);
		if (!to_remove[i - 1])
		{
			to_remove[i - 1] = NULL;
			ft_free_strs(to_remove);
			return (NULL);
		}
		i++;
	}
	return (to_remove);
}

static void	unset_variable(t_data *data, char **new_env, char **to_remove)
{
	int	i;
	int	j;
	int	k;
	int	are_equals;

	i = 0;
	j = 0;
	while (data->env[i])
	{
		are_equals = 0;
		k = 0;
		while (to_remove[k])
		{
			are_equals = ft_strncmp(to_remove[k], data->env[i],
					ft_strlen(to_remove[k]));
			if (!are_equals && data->env[i][ft_strlen(to_remove[k])] == '=')
				break ;
			k++;
		}
		if (!are_equals && data->env[i][ft_strlen(to_remove[k])] == '=')
			free(data->env[i]);
		else
			new_env[j++] = data->env[i];
		i++;
	}
	new_env[j] = NULL;
	ft_free_strs(to_remove);
}
