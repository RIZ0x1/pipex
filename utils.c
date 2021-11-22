/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:18:14 by jcarlena          #+#    #+#             */
/*   Updated: 2021/11/22 20:16:20 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define IN 0
#define OUT 1

void	the_end(int ext)
{
	char	*error;

	if (ext != 0)
	{
		if (ext == ERR_ARG)
			write(2, "pipex: error: Wrong number of arguments\n", 40U);
		if (ext == ERR_NOTFOUND)
			write(2, "pipex: error: command not found\n", 32U);
		if (ext == ERR_NOSUCHFD)
			write(3, "pipex: error: No such file or directory\n", 40U);
		exit(EXIT_FAILURE);
	}
	if (errno != 0)
	{
		error = strerror(errno);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

char	**get_path_var(char **envp)
{
	char	*var;
	int		i;

	i = 0;
	while (envp[i])
	{
		var = ft_strnstr(envp[i], "PATH=", 5);
		if (var)
			return (ft_split(&var[6], ':'));
		(i++);
	}
	return (NULL);
}

char	*get_full_path(char *command, char **envp)
{
	char		**path;
	char		*joined;
	char		*tmp;
	short int	i;

	joined = NULL;
	path = get_path_var(envp);
	tmp = ft_strjoin("/", command);
	i = 0;
	while (path[i])
	{
		joined = ft_strjoin(path[i], tmp);
		if (!access(joined, F_OK | X_OK))
		{
			break ;
		}
		else
		{
			free(joined);
			joined = NULL;
		}
		(i++);
	}
	free(tmp);
	return (joined);
}

void	child_process1(int fds[2], char *arg1, char *arg2, char **envp)
{
	int		file;
	int		exec_ret;
	char	**command;

	file = open(arg1, O_RDONLY);
	if (file == -1)
		the_end(ERR_NOSUCHFD);
	close(fds[0]);
	dup2(file, IN);
	dup2(fds[1], OUT);
	command = ft_split(arg2, ' ');
	if (ft_strchr(command[0], '/'))
		exec_ret = execve(command[0], command, envp);
	else
		exec_ret = execve(get_full_path(command[0], envp), command, envp);
	if (exec_ret == -1)
		the_end(ERR_NOTFOUND);
}

void	child_process2(int fds[2], char *arg3, char *arg4, char **envp)
{
	int		file;
	int		exec_ret;
	char	**command;

	file = open(arg4, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file == -1)
		the_end(0);
	dup2(fds[0], IN);
	close(fds[0]);
	close(fds[1]);
	dup2(file, OUT);
	command = ft_split(arg3, ' ');
	if (ft_strchr(command[0], '/'))
		exec_ret = execve(command[0], command, envp);
	else
		exec_ret = execve(get_full_path(command[0], envp), command, envp);
	if (exec_ret == -1)
		the_end(ERR_NOTFOUND);
}
