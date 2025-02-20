#ifndef MINISHELL_H
# define MINISHELL_H

# define NONEWLINE 'N'
# define NEWLINE 'n'
# define ERR_MALLOC "minishell: memory allocation failed\n"
# define ERR_SYNTAX "minishell: syntax error\n"

typedef struct s_data		t_data;
typedef struct s_token		t_token;
typedef struct s_operators	t_operators;

typedef enum e_type
{
	NAME,
	CMD,
	FLAG,
	OPERATOR,
	WILDCARD,
	VARIABLE,
}							t_type;

// General struct
typedef struct s_data
{
	char					**env;
	t_operators				*operators;
	char					**variables;
	t_token					***cmd_lines;
	char					*buffer;

}							t_data;

// Token struct
typedef struct s_token
{
	void					*content;
	t_type					type;

}							t_token;

typedef struct s_operators
{
	char					pipe[2];
	char					r_in[2];
	char					r_out[2];
	char					cmd_or[3];
	char					cmd_and[3];
	char					append[3];
	char					here_doc[3];

}							t_operators;

// Init

void						init(t_data *data, t_operators *operators);
void						init_operators(t_operators *operators);

// Parse

char						**split_cmd(t_data *data);
void						parse_cmd(t_data *data);
void						join_last(char ***strs, char *str);
int							is_special(int c);
void						extract_op(char ***strs, char *str, int *index,
								int *skipped);
void						parse_strs_error(char ***strs, char *msg);
void						print_error(char *msg);

// Execute

char						*pathfinder(const char *cmd, char **env);
void						print_tokens(t_token **tokens);

// Built ins

void						custom_echo(char *buf, void *content);
void						clean_exit(char *buf);
void						custom_pwd(char *buf);
void						custom_chdir(char *buf, char *path);

t_token						*create_token(void *content, t_type type);
t_token						*assign_token(t_token **tokens, char *str,
								int index);
void						print_tokens(t_token **tokens);
char						*get_enum(t_type type);
void						custom_env(char *buf, char **env);

#endif // !
