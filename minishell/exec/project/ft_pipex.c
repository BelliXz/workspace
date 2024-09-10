/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:38:09 by paradari          #+#    #+#             */
/*   Updated: 2024/03/24 15:38:12 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *ft_findcmdpath(char **path, char **cmd)
{
    int		i;
	int		flag;
	char	*finalpath;

	if (access(cmd[0], F_OK) == 0)
        return (cmd[0]);
	i = 0;
	flag = 0;
	while (cmd_path[i])
	{
		finalpath = ft_strjoin(cmd_path[i], cmd);
		if(access(finalpath, F_OK) == 0)
		{
			flag = 1;
			break;
		}
		free (finalpath);
		i++;
	}
	return (finalpath);
}

void	ft_dochild(char	**cmd, int OpipeI, char **path, int infile)
{
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_error_print(ERR_INFILE);
	dup2(infile, 0);
	dup2(OpipeI[1], 1);
	close(OpipeI[0]);
	if (execve(path, cmd, NULL) == -1)
		ft_error_print(ERR_CMD);
}

void	ft_doparent(char **cmd, int OpipeI, char **path, int outfile)
{
	dup2(outfile, 1);
	dup2(OpipeI[0], 0);
	close(OpipeI[1]);
	if (execve(path, cmd, NULL) == -1)
		ft_error_print(ERR_CMD);
}

void    ft_pipex(char ***cmd, char **path, char **argv)
{
    int		OpipeI[2];
	pid_t	pid;
	char	**finalpath;
	int		outfile;

	if(pipe(OpipeI) == -1)
		ft_error_print(ERR_PIPE);
	pid = fork();
	if (pid == 0)
	{
		finalpath[0] = ft_findcmdpath(path, cmd[0]);
		ft_dochild(cmd[0], OpipeI, finalpath[0], argv[1]);
		exit (0);
	}
	else 
	{
		outfile = open("")
		finalpath[1] = ft_findcmdpath(path, cmd[1]);
		ft_doparent(cmd[1], OpipeI, finalpath[1], argv[4]);
		dup2(OpipeI[0], 0);
		close(OpipeI[1]);
		dup2(outfile, 1);
		wait(NULL);
		exit (0);
	}
}