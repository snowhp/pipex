/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:06:55 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 15:13:01 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* This function will create our pipe and handle all the fd's*/
void	ft_pipex(t_pipex *pipex, char **argv, char **env)
{
	pipex->cmd1 = ft_joinsplit(argv[2], ' ', '\'');
	pipex->cmd2 = ft_joinsplit(argv[3], ' ', '\'');
	if (pipe(pipex->fd) == -1)
		ft_exit(pipex, 1);
	pipex->id = fork();
	if (pipex->id == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		ft_execute(pipex, pipex->cmd1, env);
	}
	else
	{
		waitpid(pipex->id, NULL, WNOHANG);
		if (pipex->id == -1)
			ft_exit(pipex, 2);
		close(pipex->fd[1]);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		dup2(pipex->fd[0], STDIN_FILENO);
		if (errno)
			exit(1);
		else
			ft_execute(pipex, pipex->cmd2, env);
	}
}

/* Main function tests the input that the user gave and returns errors, else
they call pipex function*/
int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_printf("Usage %s infile cmd1 cmd2 outfile", argv[0]);
		return (1);
	}
	ft_init_pipex(&pipex);
	pipex.infile_fd = open(argv[1], O_RDONLY, 0444);
	if (errno)
		ft_printf("%s: %s\n", strerror(errno), argv[1]);
	pipex.outfile_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (errno)
		ft_printf("%s: %s\n", strerror(errno), argv[4]);
	pipex.orig_stdout_fd = dup(STDOUT_FILENO);
	ft_pipex(&pipex, argv, env);
	ft_exit(&pipex, 0);
}
