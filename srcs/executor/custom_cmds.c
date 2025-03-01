#include "libft.h"
#include "minishell.h"
// clang-format off
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>
// clang-format on
#include <unistd.h>

void	custom_dup2(int fd, char *flag)
{
	if (!ft_strcmp(flag, "STDIN"))
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit(EXIT_FAILURE);
		}
	}
	else if (!ft_strcmp(flag, "STDOUT"))
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	custom_pipe(int fds[2])
{
	if (pipe(fds) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(EXIT_FAILURE);
	}
}

void	check_fork(pid_t pid, int wefd, int refd)
{
	if (pid < 0)
	{
		close(wefd);
		close(refd);
		ft_putstr_fd(strerror(errno), 2);
		exit(EXIT_FAILURE);
	}
}

void	close_fds(int wefd, int refd)
{
	close(wefd);
	close(refd);
}

void	custom_unlink(char *filepath)
{
	if (unlink(filepath) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(EXIT_FAILURE);
	}
}
