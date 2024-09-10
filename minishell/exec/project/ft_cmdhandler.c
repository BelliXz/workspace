/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:28:45 by paradari          #+#    #+#             */
/*   Updated: 2024/03/27 02:28:47 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// char    *ft_findcmdpath(char **path, char **cmd)
// {
//     int		i;
// 	int		flag;
// 	char	*finalpath;

// 	if (access(cmd[0], F_OK) == 0)
//         return (cmd[0]);
// 	i = 0;
// 	flag = 0;
// 	while (cmd_path[i])
// 	{
// 		finalpath = ft_strjoin(cmd_path[i], cmd);
// 		if(access(finalpath, F_OK) == 0)
// 		{
// 			flag = 1;
// 			break;
// 		}
// 		free (finalpath);
// 		i++;
// 	}
// 	return (finalpath);
// }