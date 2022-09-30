/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:47:56 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/06 10:47:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	unl_heredoc(t_data *data, int file, char *buf)
{
	if (!buf)
		write (1, "\n", 1);
	free(buf);
	close(file);
	data->infile_fd = open(".heredoc_tmp", O_RDONLY);
	if (data->infile_fd < 0)
	{
		unlink(".heredoc_tmp");
		msg_perror_exit("open");
	}
}

void	heredoc(char *limiter, t_data *data)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_perror_exit("open : error");
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (!buf || (!ft_strncmp(limiter, buf, ft_strlen(limiter))
				&& buf[ft_strlen(limiter)] == '\n'))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	unl_heredoc(data, file, buf);
}
