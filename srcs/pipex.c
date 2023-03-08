/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:06:55 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/08 12:59:06 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* This function will create our pipe and handle all the fd's*/
void	pipex(int infile, int outfile, char **argv, char **env)
{
	int	fd[2];
	if(pipe(fd) == -1)/* Error check */
	{
		printf("Error opening the pipe");
		return;
	}
	int	id = fork();
	if(id == 0)/* Child process */
	{
		close(fd[0]);//Read end is closed because it is unused
		dup2(infile, STDIN_FILENO);//Standart input becomes infile fd
		dup2(fd[1], STDOUT_FILENO);//Standart output becomes fd[1] Write End of the pipe
	
	}
	else/* Parent process */
	{
		if(id == -1)
		{
			printf("Error duplicating calling process");// Checking for fork()
			return;
		}
		close(fd[1]);//Write end is closed because it is unused
		wait(0);//Wait for child process
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		
	}
}

/* Main function tests the input that the user gave and returns errors, else they call pipex function*/
int	main(int argc, char **argv, char **env)
{
	(void) argv;
	(void) env;
	if(argc != 5 )
	{
		printf("Usage %s infile cmd1 cmd2 outfile", argv[0]);//REPLACE THIS PRINTF
		return (1);
	}
	int f1 = open(argv[1] , O_RDONLY, 0777);
	if(f1 == -1)
	{
		perror("\033[31m[Error] \033[37mOpening infile");
		return (1);
	}
	int f2 = open(argv[5] , O_CREAT | O_RDWR | O_TRUNC , 0777);
	if(f2 == -1)
	{
		perror("\033[31m[Error] \033[37mOpening outfile");
		return (1);
	}
	pipex(f1, f2, argv, env);
	return (0);
}