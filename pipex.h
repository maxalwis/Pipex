/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:27:31 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/22 15:33:10 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "Superlibft/Includes/superlibft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	int		prev_fd;
	int		index;
	int		i;
	int		nb_cmds;
	int		cmd_start_index;
	pid_t	*pid;
}	t_pipex;

typedef struct s_heredoc
{
	int		is_active;
	char	*limiter;
}	t_heredoc;

//execute_command
void	execute_command(char **args, char **envp);

// free_split
void	free_split(char **split);

// cmd_path
char	*cmd_path(char **path, char *cmd);
char	*search_path(char **envp);

// multiple pipes
void	infinite_pipes(t_pipex *pipex, char **av, char **envp);

//handle heredoc
void	detect_heredoc(t_heredoc *heredoc, char **av);
int		handle_heredoc(t_pipex *pipex, t_heredoc *heredoc);
int		init_files(t_pipex *pipex, t_heredoc *heredoc, int ac, char **av);

//close_fd
void	close_fd(t_pipex *pipex);

#endif
