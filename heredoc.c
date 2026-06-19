/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:30:37 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/17 17:10:07 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	detect_heredoc(t_heredoc *heredoc, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		heredoc->is_active = 1;
		heredoc->limiter = av[2];
	}
	else
	{
		heredoc->is_active = 0;
		heredoc->limiter = NULL;
	}
}

int	handle_heredoc(t_pipex *pipex, t_heredoc *heredoc)
{
	int		heredoc_pipe[2];
	char	*line;

	if (pipe(heredoc_pipe) == -1)
		return (perror("pipe heredoc_pipe"), 1);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0, 0);
		if (!line)
			break ;
		if (ft_strncmp(line, heredoc->limiter, ft_strlen(heredoc->limiter)) \
			== 0 && line[ft_strlen(heredoc->limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, heredoc_pipe[1]);
		free(line);
	}
	close (heredoc_pipe[1]);
	pipex->infile = heredoc_pipe[0];
	get_next_line(0, 1);
	return (0);
}

int	heredoc_mode(t_pipex *pipex, t_heredoc *heredoc, int ac, char **av)
{
	pipex->cmd_start_index = 3;
	if (handle_heredoc(pipex, heredoc) != 0)
		return (0);
	pipex->outfile = open(av[ac - 1], O_APPEND | O_CREAT | O_WRONLY \
		, 0644);
	if (pipex->outfile == -1)
		return (perror("open outfile"), 0);
	pipex->nb_cmds = ac - 4;
	return (1);
}

int	normal_mode(t_pipex *pipex, int ac, char **av)
{
	pipex->cmd_start_index = 2;
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->infile == -1 || pipex->outfile == -1)
	{
		if (pipex->infile != -1)
			close(pipex->infile);
		if (pipex->outfile != -1)
			close(pipex->outfile);
		return (perror("open"), 0);
	}
	pipex->nb_cmds = ac - 3;
	return (1);
}

int	init_files(t_pipex *pipex, t_heredoc *heredoc, int ac, char **av)
{
	if (heredoc->is_active)
		heredoc_mode(pipex, heredoc, ac, av);
	else
		normal_mode(pipex, ac, av);
	return (1);
}
