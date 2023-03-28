#include <unistd.h>
#include "./libft/libft.h"

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

int	main(int argc, char **argv, char **envp)
{
	char *path;

	char **cmd;

	cmd = ft_joinsplit(argv[1], ' ', '\'');
	path = ft_path(cmd[0], envp);
	execve(path, cmd, envp);
	return (0);
}