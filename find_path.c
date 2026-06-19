/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:17:16 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/17 17:03:52 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*cmd_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*full_path;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (NULL);
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*resolve_exec_path(char **args, char **envp)
{
	char	*path;
	char	**paths_splitted;
	char	*exec_path;

	path = search_path(envp);
	if (!path)
	{
		ft_putstr_fd("Error : PATH not found\n", 2);
		exit (127);
	}
	paths_splitted = ft_split(path, ':');
	if (!paths_splitted)
	{
		free_split(paths_splitted);
		exit (1);
	}
	exec_path = cmd_path(paths_splitted, args[0]);
	if (!exec_path)
	{
		free_split(paths_splitted);
		ft_putstr_fd("Error : Command not found\n", 2);
		free_split(args);
		exit (127);
	}
	return (free_split(paths_splitted), exec_path);
}

void	execute_command(char **args, char **envp)
{
	char	*exec_path;

	exec_path = resolve_exec_path(args, envp);
	if (execve(exec_path, args, envp) == -1)
	{
		perror("execve");
		free(exec_path);
		free_split(args);
		exit (126);
	}
	exit (1);
}
