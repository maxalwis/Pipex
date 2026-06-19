/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:05:33 by maalwis           #+#    #+#             */
/*   Updated: 2025/04/17 15:07:23 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Cas d'utilisation :
// 0. Sans bonus : ./pipex file1 cmd1 cmd2 file2
// Identique a :	$> < file1 cmd1 | cmd2 > file2

// 1. Bonus 1 --> gerer plusieurs pipes :
//$> ./pipex file1 cmd1 cmd2 ...	 cmdn file2
// Identique a : 							
//< file1 cmd1 | cmd2 | ... | cmdn > file2

// 2. Bonus 2 --> gerer heredoc : $> ./pipex here_doc LIMITER cmd cmd1 file
// Identique a : 						cmd << LIMITER | cmd1 >> file

int	main(int ac, char **av, char **envp)
{
	t_pipex		pipex;
	t_heredoc	heredoc;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	if (ac < 5)
		return (ft_putstr_fd("Error : Regardez les cas d'utilisation\n", 2), 1);
	detect_heredoc(&heredoc, av);
	if (!init_files(&pipex, &heredoc, ac, av))
		return (1);
	infinite_pipes(&pipex, av, envp);
	close_fd(&pipex);
	return (0);
}
