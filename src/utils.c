/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:11:20 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 12:16:59 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* This function will execute the given commands and free properly
if fails to find path*/
void	ft_execute(t_pipex *pipex, char **cmd, char **env)
{
	if (access(cmd[0], F_OK) == 0)
		pipex->path = cmd[0];
	else
		pipex->path = ft_path(cmd[0], env);
	if (!pipex->path)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("Command not found: %s\n", cmd[0]);
		ft_exit(pipex, 3);
	}
	if (execve(pipex->path, cmd, env) == -1)
		ft_exit(pipex, 4);
}

char	*ft_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

/* This function will print specific errors and free cmd's.*/
void	ft_exit(t_pipex *pipex, int ecode)
{
	int	i;

	i = 0;
	if (pipex->path)
		free(pipex->path);
	if (pipex->cmd1)
	{
		while (pipex->cmd1[i])
			free(pipex->cmd1[i++]);
		free(pipex->cmd1);
	}
	i = 0;
	if (pipex->cmd2)
	{
		while (pipex->cmd2[i])
			free(pipex->cmd2[i++]);
		free(pipex->cmd2);
	}
	if (pipex->infile_fd != 0)
		close(pipex->infile_fd);
	if (pipex->outfile_fd != 0)
		close(pipex->outfile_fd);
	exit(ecode);
}

void	ft_fdchange(t_pipex *pipex)
{
	if (pipex->id == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		if (errno)
			ft_exit(pipex, EXIT_FAILURE);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		dup2(pipex->fd[0], STDIN_FILENO);
		if (errno)
			ft_exit(pipex, EXIT_FAILURE);
	}
}

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->id = 0;
	pipex->orig_stdout_fd = 0;
	pipex->fd[0] = 0;
	pipex->fd[1] = 0;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->path = NULL;
}
