/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:40:37 by paradari          #+#    #+#             */
/*   Updated: 2024/03/24 14:40:42 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	**ft_collect_path(char	*path)
{
	char	**cmd_path;
	int		i;

	i = 0;
	cmd_path = ft_split(path, ':');
	while(cmd_path[i])
	{
		cmd_path[i] = ft_strrejoin(cmd_path[i], "/");//not have rejoin
		i++;
	}
	return (cmd_path);
}

char	**ft_splitpath(char **envp)
{
	char	**path;
	int		i;
	int		p_index;

	p_index = -1;
	i = 0;
	while(envp[i])
	{
		if (!(ft_memcmp(envp[i], "PATH=", 5)))
		{
			p_index = i;
			break;
		}
		i++;
	}
	if (p_index >= 0)
	{
		path = ft_collect_path(envp[p_index] + 5);
		return (path);
	}
	return (NULL);
}

char	***ft_splitcmd(char **argv)
{
	char	***cmd;
	int		i;

	cmd = (char ***)malloc(sizeof(char **) * 3);
	if (!cmd)
		return (NULL);
	i = 1;
	while (i++ < 3)
		cmd[i - 2] = ft_split(argv[i], ' ');
	return (cmd);
}

int main(int argc, char **argv, char **envp)
{
    char	***cmd;
	char 	**path;
	int		i;
	int		j;

    if (argc == 5)
	{
		path = ft_splitpath(envp);
		cmd = ft_splitcmd(argv);//n
		ft_pipex(cmd, path, argv);
	}
	else
		ft_printf("The program must take 4 arguments\n");
	
    return 0;
}
