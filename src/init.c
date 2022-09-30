/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:16:27 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/24 19:09:16 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_data(t_data *data)
{
	data->env_path = NULL;
	data->cmd_paths = NULL;
	data->cmd_args = NULL;
	data->cmd = NULL;
	data->pipe = NULL;
	data->pid = NULL;
	data->is_heredoc = 0;
}
