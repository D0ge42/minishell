/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:01:15 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/22 12:22:19 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	skip_space(t_parser *parser, int *index);

int	split_cmd(t_parser *parser)
{
	int	i;

	parser->tokens = ft_calloc(1, sizeof(t_token *));
	if (parser->tokens == NULL)
		return (print_error(ERR_MALLOC));
	i = 0;
	parser->skipped = 1;
	while (parser->tokens != NULL && parser->buffer[i] != '\0')
	{
		if (skip_space(parser, &i))
			continue ;
		if (is_dquote(parser->buffer[i]))
			extract(parser, &i, is_dquote, DQUOTE);
		else if (is_quote(parser->buffer[i]))
			extract(parser, &i, is_quote, QUOTE);
		else if (is_special(parser->buffer[i]))
			extract(parser, &i, NULL, OPERATOR);
		else
			extract(parser, &i, is_special, NORMAL);
	}
	return (0);
}

static int	skip_space(t_parser *parser, int *index)
{
	if (parser->buffer[*index] == ' ')
	{
		(*index)++;
		parser->skipped = 1;
		return (1);
	}
	return (0);
}
