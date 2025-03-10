/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lonulli <lonulli@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:34:23 by lonulli           #+#    #+#             */
/*   Updated: 2025/03/07 22:34:24 by lonulli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
// clang-format off
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
// clang-format on
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void	free_memory(t_data *data, char **args)
{
	if (data->env)
		ft_free_strs(data->env);
	if (args)
		ft_free_strs(args);
	if (data->tokens)
		free_tokens(data->tokens);
	rl_clear_history();
}
