/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:27:31 by paradari          #+#    #+#             */
/*   Updated: 2024/03/24 15:27:33 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_error_print(char *flag)
{
    if (*flag == ERR_CMD)
    {
        perror(ERR_CMD);
        exit (127);
    }
    else if (*flag == ERR_INFILE)
    {
        perror(ERR_INFILE);
        exit (126);
    }
    else
    {
        perror("");
        exit (1);
    }
}