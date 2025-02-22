#include "libft.h"
#include "minishell.h"
// clang-format off
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
// clang-format on
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	read_line(t_data *data);

int			g_status;

int	main(void)
{
	static t_data	data;
	static t_parser	parser;

	init(&data, &parser);
	while (1)
	{
		read_line(&data);
		parse_cmd(&data);
		custom_echo(&data);
		clean_exit(&data);
		custom_pwd(&data);
		custom_chdir(&data);
		custom_env(&data);
		custom_export(&data);
		custom_unset(&data);
		free(data.parser->buffer);
		ft_free_strs(data.parser->strs);
		parser.strs = NULL;
	}
	exit(0);
}

static void	read_line(t_data *data)
{
	data->parser->buffer = readline("B_Bros > ");
	add_history(data->parser->buffer);
}
