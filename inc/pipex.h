/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:07:02 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/29 17:34:09 by user             ###   ########.fr       */
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
	int		id;
	int		fd[2];
	char	**cmd1;
	char	**cmd2;
	char	*path;
}	t_pipex;

void	ft_pipex(t_pipex *pipex, char **argv, char **env);
void	ft_errorn(t_pipex *pipex, int errorn);
char	*ft_path(char *cmd, char **env);
void	execute(t_pipex *pipex, char **cmd, char **env);
void	ft_init_pipex(t_pipex *pipex);

#endif