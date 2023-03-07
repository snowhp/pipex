/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:06:55 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/07 07:02:54 by tde-sous         ###   ########.fr       */
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
		close(fd[0]);
		/* Read from in-file*/
		char	*str;
		while(str)
		{
			str = ft_strjoin(str, get_next_line(infile)); // #MALLOC
		}
		dup2(fd[1], STDOUT_FILENO);
		/*
			Execute cmd1 with input from read in-file
				change fd's using dup2()
				exec will need to find the path and test
		*/
		execve("/usr/bin/ping", argv[2], env);
	}
	else/* Parent process */
	{
		if(id = -1)
		{
			printf("Error duplicating calling process");// Checking for fork()
			return;
		}
		close(fd[1]);
		wait(0);//Wait for child process
		/*	
		Execute cmd2 with input from output of cmd1
			same as cmd1
		Write on outfile
		*/

	}
}

/* Main function tests the input that the user gave and returns errors, else they call pipex function*/
int	main(int argc, char **argv, char **env)
{
	if(argc != 5 )
	{
		printf("Usage ./pipex infile cmd1 cmd2 outfile");
		return (1);
	}
	int f1 = open(argv[1] , O_RDONLY, 0777); /* Read only flag*/
	if(f1 == -1)
	{
		perror("Error opening infile!");
		return (1);
	}
	int f2 = open(argv[5] , O_CREAT | O_RDWR | O_TRUNC , 0777); /* Create file if doesnt exist, Read Write, Truncate (clear the file), */
	if(f2 == -1)
	{
		perror("Error opening/creating outfile!");
		return (1);
	}
	pipex(f1, f2, argv, env);
	return (0);
}