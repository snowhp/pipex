#include "../includes/pipex.h"

/* This function will execute the given commands and free properly if fails to find path*/
void	execute(char **cmd, char **env)
{
	char	*path;

	path = ft_path(cmd, env);
	if(execve(path, cmd, env) == -1)
		perror("\033[31m[Error] \033[37mExecuting command");
}

char *ft_path(char *argv, char **env)
{
	 	
}

/* This function will print specific errors and free cmd's.*/
void ft_errorn(char **cmd1, char **cmd2, int errorn)
{
	int	i;

	if(errorn == 1)
		perror("\033[31m[Error] \033[37mCreating pipe");
	if(errorn == 2)
		perror("\033[31m[Error] \033[37mCreating new process using fork");
	i = 0;
	while(cmd1[i])
		free(cmd1[i++]);
	free(cmd1);
	i = 0;
	while(cmd2[i])
		free(cmd2[i++]);
	free(cmd2);
	exit(1);
}