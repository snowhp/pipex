/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:06:55 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/16 19:27:05 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* This function will create our pipe and handle all the fd's*/
void	pipex(int infile, int outfile, char **argv, char **env)
{
	char	**cmd1;
	char	**cmd2;
	int		id1;
	int		id2;
	int		fd[2];	

	id1 = fork();
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');//resolver "'"
	if (id1 == 0)
	{
		if (pipe(fd) == -1)
			ft_errorn(cmd1, cmd2, 1);
		id2 = fork();
		if (id2 == 0)
		{
			close(fd[0]);
			dup2(infile, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			if (execute(cmd1, env) == 1)
				ft_errorn(cmd1, cmd2, 3);
		}
		else
		{
			wait(0);
			if (id2 == -1)
				ft_errorn(cmd1, cmd2, 2);
			close(fd[1]);
			dup2(outfile, STDOUT_FILENO);
			dup2(fd[0], STDIN_FILENO);
			if (execute(cmd2, env) == 1)
				ft_errorn(cmd1, cmd2, 3);
		}
	}
	else
	{
		if (id1 == -1)
			ft_errorn(cmd1, cmd2, 2);
		while (wait(NULL) != -1 || errno != ECHILD)//Waiting for all childs to finish
		ft_errorn(cmd1, cmd2, 0);
	}
}

/* Main function tests the input that the user gave and returns errors, else
they call pipex function*/
int	main(int argc, char **argv, char **env)
{
	int		f1;
	int		f2;

	if (argc != 5)
	{
		printf("Usage %s infile cmd1 cmd2 outfile", argv[0]);//PRINTF
		return (1);
	}
	f1 = open(argv[1], O_RDONLY, 0444);
	if (errno != 0)
	{
		perror("Opening infile");
		exit(EXIT_FAILURE);
	}
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (errno != 0)
	{
		perror("Opening outfile");
		exit (EXIT_FAILURE);
	}
	pipex(f1, f2, argv, env);//Missing closing pipes
	exit (EXIT_SUCCESS);
}
