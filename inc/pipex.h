/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:11:05 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 12:17:04 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		orig_stdout_fd;
	int		id;
	int		fd[2];
	char	**cmd1;
	char	**cmd2;
	char	*path;
}	t_pipex;

void	ft_pipex(t_pipex *pipex, char **argv, char **env);
void	ft_exit(t_pipex *pipex, int ecode);
char	*ft_path(char *cmd, char **env);
void	ft_execute(t_pipex *pipex, char **cmd, char **env);
void	ft_init_pipex(t_pipex *pipex);
void	ft_fdchange(t_pipex *pipex);

#endif
