/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:08:55 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 21:08:55 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent_free(t_data *data)
{
	int	i;

	i = 0;
	if (data->infile_fd >= 0)
		close(data->infile_fd);
	close(data->outfile_fd);
	if (data->is_heredoc)
		unlink(".heredoc_tmp");
	while (data->cmd_paths && data->cmd_paths[i])
	{
		free(data->cmd_paths[i]);
		i++;
	}
	if (data->cmd_paths)
		free(data->cmd_paths);
	free(data->pipe);
	free(data->pid);
}

void	child_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_args && data->cmd_args[i])
	{
		free(data->cmd_args[i]);
		i++;
	}
	i = 0;
	while (data->cmd_paths && data->cmd_paths[i])
	{
		free(data->cmd_paths[i]);
		i++;
	}
	if (data->cmd_args)
		free(data->cmd_args);
	if (data->cmd)
		free(data->cmd);
	if (data->cmd_paths)
		free(data->cmd_paths);
	free(data->pipe);
	free(data->pid);
}

void	pipe_free(t_data *data)
{
	if (data->infile_fd >= 0)
		close(data->infile_fd);
	close(data->outfile_fd);
	if (data->is_heredoc)
		unlink(".heredoc_tmp");
	free(data->pipe);
	error_msg("environnement : error\n");
	exit(1);
}
