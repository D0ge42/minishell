/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:55:33 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/24 14:34:04 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static int	extract_op(t_parser *parser, int *index);
static int	extract_str(t_parser *parser, int *index, int (*ctrl)(int),
				t_mode mode);

void	extract(t_parser *parser, int *index, int (*ctrl)(int), t_mode mode)
{
	t_token	**tmp_tokens;

	if (mode == OPERATOR)
		extract_op(parser, index);
	else
		extract_str(parser, index, ctrl, mode);
	if (parser->str == NULL)
		return (parse_error(parser));
	if (!parser->skipped && mode != OPERATOR)
		return (join_last(parser));
	if (gen_token(parser, mode))
		return (parse_error(parser));
	parser->str = NULL;
	tmp_tokens = parser->tokens;
	parser->tokens = add_token(parser->tokens, parser->token);
	if (parser->tokens == NULL)
	{
		free_tokens(tmp_tokens);
		free_token(parser->token);
		parser->token = NULL;
		print_error(ERR_MALLOC);
		return (parse_error(parser));
	}
}

static int	extract_str(t_parser *parser, int *index, int (*ctrl)(int),
		t_mode mode)
{
	int	i;

	i = *index;
	parser->skipped = 1;
	if (mode != NORMAL)
		i++;
	while (parser->buffer[i] != '\0' && !(*ctrl)(parser->buffer[i]))
		i++;
	if (parser->buffer[i] == '\0' && mode != NORMAL)
		return (print_error1(ERR_SYNTAX, " unclosed quotes"));
	if (mode != NORMAL)
		i++;
	parser->str = ft_strndup(&parser->buffer[*index], i - *index);
	*index = i;
	if (parser->str == NULL)
		return (print_error(ERR_MALLOC));
	return (0);
}

static int	extract_op(t_parser *parser, int *index)
{
	parser->skipped = 0;
	if (parser->buffer[*index] == '|')
		parser->str = if_double(parser->buffer, index, "||", "|");
	else if (parser->buffer[*index] == '(')
		parser->str = ft_strdup("(");
	else if (parser->buffer[*index] == ')')
		parser->str = ft_strdup(")");
	else if (parser->buffer[*index] == '>')
		parser->str = if_double(parser->buffer, index, ">>", ">");
	else if (parser->buffer[*index] == '<')
		parser->str = if_double(parser->buffer, index, "<<", "<");
	else if (!ft_strncmp(&parser->buffer[*index], "&&", 2))
	{
		(*index)++;
		parser->str = ft_strdup("&&");
	}
	else
		return (print_error1(ERR_SYNTAX, " near unexpected token `&'"));
	(*index)++;
	if (parser->str == NULL)
		return (print_error(ERR_MALLOC));
	return (0);
}
