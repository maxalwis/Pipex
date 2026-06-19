/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:32:33 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/22 16:48:32 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	safe_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		perror("dup2");
		return ;
	}
}

void	close_fd(t_pipex *pipex)
{
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->prev_fd != -1)
		close(pipex->prev_fd);
	if (pipex->pipe_fd[0] != -1)
		close(pipex->pipe_fd[0]);
	if (pipex->pipe_fd[1] != -1)
		close(pipex->pipe_fd[1]);
}

void	child_process(t_pipex *pipex, char **av, char **envp)
{
	char	**cmd_args;

	free(pipex->pid);
	pipex->pid = NULL;
	if (pipex->index == 0)
		safe_dup2(pipex->infile, STDIN_FILENO);
	else
		safe_dup2(pipex->prev_fd, STDIN_FILENO);
	if (pipex->index == pipex->nb_cmds - 1)
		safe_dup2(pipex->outfile, STDOUT_FILENO);
	else
		safe_dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close_fd(pipex);
	cmd_args = ft_split(av[pipex->index + pipex->cmd_start_index], ' ');
	execute_command(cmd_args, envp);
	free_split(cmd_args);
}

void	parent_process(t_pipex *pipex)
{
	if (pipex->prev_fd != -1)
		close(pipex->prev_fd);
	if (pipex->pipe_fd[1] != -1)
		close(pipex->pipe_fd[1]);
	pipex->prev_fd = pipex->pipe_fd[0];
}

void	infinite_pipes(t_pipex *pipex, char **av, char **envp)
{
	pipex->pid = malloc(sizeof(pid_t) * pipex->nb_cmds);
	if (!pipex->pid)
		(perror("malloc pid"), exit (1));
	pipex->prev_fd = -1;
	while (pipex->index < pipex->nb_cmds)
	{
		pipex->pipe_fd[0] = -1;
		pipex->pipe_fd[1] = -1;
		if (pipex->index < pipex->nb_cmds - 1 && pipe(pipex->pipe_fd) == -1)
			(perror("pipe"), exit(1));
		pipex->pid[pipex->index] = fork();
		if (pipex->pid[pipex->index] == -1)
			(perror("fork"), exit(1));
		if (pipex->pid[pipex->index] == 0)
			child_process(pipex, av, envp);
		else
			parent_process(pipex);
		pipex->index++;
	}
	while (pipex->i < pipex->nb_cmds)
		waitpid(pipex->pid[pipex->i++], NULL, 0);
	free(pipex->pid);
	close_fd(pipex);
}
