/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:06:55 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/10 07:47:33 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* This function will create our pipe and handle all the fd's*/
void	pipex(int infile, int outfile, char **argv, char **env)
{
	int	id1 = fork();
	
	char **cmd1 = ft_split(argv[2], " ");
	char **cmd2 = ft_split(argv[3], " ");
	if (id1 == 0)
	{
		int	fd[2];	
		
		if(pipe(fd) == -1)
			ft_errorn(cmd1, cmd2, 1);
		int	id2 = fork();
		if(id2 == 0)
		{
			close(fd[0]);
			wait(0);
			dup2(infile, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			execute(argv[2], env);
		}
		else
		{
			if (id2 == -1)
				ft_errorn(cmd1, cmd2, 2);
			close(fd[1]);
			dup2(outfile, STDOUT_FILENO);
			dup2(fd[0], STDIN_FILENO);
			execute(argv[3], env);
		}

	}
	else
	{
		if (id1 == -1)
			ft_errorn(cmd1, cmd2, 2);
		while(wait(NULL) != -1 || errno != ECHILD)
			printf("Waited for child to finish\n");
		ft_errorn(cmd1, cmd2, 0);
	}
}

/* Main function tests the input that the user gave and returns errors, else they call pipex function*/
int	main(int argc, char **argv, char **env)
{
	(void) argv;
	(void) env;
	if (argc != 5 )
	{
		printf("Usage %s infile cmd1 cmd2 outfile", argv[0]);//REPLACE THIS PRINTF
		return (1);
	}
	int f1 = open(argv[1] , O_RDONLY, 0777);
	if (f1 == -1)
	{
		perror("\033[31m[Error] \033[37mOpening infile");
		return (1);
	}
	int f2 = open(argv[5] , O_CREAT | O_RDWR | O_TRUNC , 0777);
	if (f2 == -1)
	{
		perror("\033[31m[Error] \033[37mOpening outfile");
		return (1);
	}
	pipex(f1, f2, argv, env);
	return (0);
}