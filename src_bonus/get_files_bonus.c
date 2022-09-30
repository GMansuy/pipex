/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:47:47 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 21:11:42 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_out(char *file_name, t_data *data)
{
	if (data->is_heredoc)
		data->outfile_fd = open(file_name, O_CREAT
				| O_WRONLY | O_APPEND, 0000644);
	else
		data->outfile_fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (data->outfile_fd < 0)
		msg_perror_exit("open");
}

void	get_in(char **argv, t_data *data)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		heredoc(argv[2], data);
	else
	{
		data->infile_fd = open(argv[1], O_RDONLY);
		if (data->infile_fd < 0)
		{
			perror("open");
			data->id++;
			data->curr_cmd ++;
		}
	}
}

int	get_heredoc(char *arg, t_data *data)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		data->is_heredoc = 1;
		return (6);
	}
	else
	{
		data->is_heredoc = 0;
		return (5);
	}
}
