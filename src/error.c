/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:47:27 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/06 10:47:27 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error_msg(char *err)
{
	ft_putstr_fd(err, 2);
	return (1);
}

void	msg_perror_exit(char *err)
{
	perror(err);
	exit (-1);
}

void	msg_pipe(char *arg)
{
	char		*tmp;
	char		*err;
	const char	*fildir = "bash: no such file or directory: ";
	const char	*cmdnot = "bash: command not found: ";

	if (strncmp(arg, "/", 1) == 0 || strncmp(arg, "./", 2) == 0)
		tmp = ft_strjoin((char *)fildir, arg);
	else
		tmp = ft_strjoin((char *)cmdnot, arg);
	err = ft_strjoin(tmp, "\n");
	free(tmp);
	write(2, err, ft_strlen(err));
	free(err);
}
