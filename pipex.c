/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:06:55 by tde-sous          #+#    #+#             */
/*   Updated: 2023/02/26 19:25:12 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* This function will create our pipe and handle all the fd's*/
void	pipex(int infile, int outfile, char **argv, char **env)
{
	int	fd[2];
	if(pipe(fd) == -1)/* Error check */
		return;
	int	id = fork();
	if(id == 0)/* Child process */
	{
		close(fd[0]);
		/*	Read from in-file
			Execute cmd1 with input from read in-file
				exec will need to find the path and test
		*/
	}
	else/* Parent process */
	{
		close(fd[1]);
		wait(0);
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
		return (0);
	}
	int f1 = open(argv[1] , O_RDONLY, 0777); /* Read only flag*/
	if(f1 == -1)
	{
		perror("Error opening infile!");
		return (0);
	}
	int f2 = open(argv[5] , O_CREAT, O_RDWR , O_TRUNC , 0777); /* Create file if doesnt exist, Read Write, Truncate (clear the file), */
	if(f2 == -1)
	{
		perror("Error opening/creating outfile!");
		return (0);
	}
	pipex()
	return (0);
}
