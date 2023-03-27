/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:11:20 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/27 12:05:51 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* This function will execute the given commands and free properly if fails to find path*/
int	execute(t_pipex *pipex, char **cmd, char **env)
{
	char	*path;

	path = ft_path(cmd[0], env);
	if (!path)
	{
		ft_errorn(pipex, 3);
		return (1);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("Executing command");
		exit(EXIT_FAILURE);
	}
	return (0);//check return
}

char *ft_path(char *cmd, char **env)
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
void ft_errorn(t_pipex *pipex, int errorn)
{
	int	i;

	i = 0;
	while(pipex->cmd1[i])
		free(pipex->cmd1[i++]);
	free(pipex->cmd1);
	i = 0;
	while(pipex->cmd2[i])
		free(pipex->cmd2[i++]);
	free(pipex->cmd2);
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	if (errorn == 1)
		perror("Creating pipe");
	if (errorn == 2)
		perror("Creating new process using fork");
	if (errorn == 3)
		perror("Command not found");
	if(errorn == 0)
		return;
	exit(EXIT_FAILURE);
}

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->cmd1 = 0;
	pipex->cmd2 = 0;
}