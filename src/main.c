/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:48:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/06 10:48:02 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	allocate_pipe(int argc, t_data *data)
{
	data->cmd_nbr = argc - 3 - data->is_heredoc;
	data->pipe_nbr = 2 * (data->cmd_nbr - 1);
	data->pipe = (int *)malloc(sizeof(int) * data->pipe_nbr);
	if (!data->pipe)
		data->pid = NULL;
	else
		data->pid = (int *)malloc(sizeof(int) * data->cmd_nbr);
	if (!data->pid)
	{
		close(data->infile_fd);
		close(data->outfile_fd);
		free(data->pipe);
		msg_perror_exit("malloc");
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc != 5)
		return (error_msg("usage : ./pipex file1 cmd1 cmd2 file2\n"));
	data.id = -1;
	init_data(&data);
	data.curr_cmd = -1;
	get_in(argv, &data);
	get_out(argv[argc - 1], &data);
	allocate_pipe(argc, &data);
	get_cmd_paths(envp, &data);
	init_pipes(&data);
	while (++(data.curr_cmd) < data.cmd_nbr)
		child(&data, argv, envp);
	close_pipes(&data);
	while (++data.id < data.cmd_nbr)
		waitpid(data.pid[data.id], NULL, 0);
	parent_free(&data);
	return (0);
}
