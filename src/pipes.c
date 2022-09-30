/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:48:07 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/06 10:48:07 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->pipe_nbr))
	{
		close(data->pipe[i]);
		i++;
	}
}

void	init_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		if (pipe(data->pipe + 2 * i) < 0)
		{
			parent_free(data);
			msg_perror_exit("pipe");
		}
		i++;
	}
}
