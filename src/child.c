/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:47:19 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/06 10:47:19 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	check_abs_path(char *cmd, char **paths)
{
	if (ft_strncmp(cmd, "/", 1) == 0 || ft_strncmp(cmd, "./", 2) == 0)
	{
		if (access(cmd, 0) == 0)
			return (2);
		else
			return (0);
	}
	if (!paths)
		return (0);
	return (1);
}

static char	*find_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	int		signal;

	signal = check_abs_path(cmd, paths);
	if (!signal)
		return (NULL);
	if (signal == 2)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		if (!tmp)
			return (NULL);
		command = ft_strjoin(tmp, cmd);
		if (!command)
			return (NULL);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	set_dup(int in, int out)
{
	dup2(in, 0);
	dup2(out, 1);
}

void	child_cmd(char **argv, t_data *data)
{
	data->cmd_args = ft_split(argv[2 + data->is_heredoc + data->curr_cmd],
			' ');
	if (!data->cmd_args)
		data->cmd = NULL;
	else
		data->cmd = find_cmd(data->cmd_paths, data->cmd_args[0]);
	if (!data->cmd)
	{
		if (data->infile_fd >= 0)
			close(data->infile_fd);
		if (data->outfile_fd >= 0)
			close(data->outfile_fd);
		close(0);
		close(1);
		msg_pipe(data->cmd_args[0]);
		close_pipes(data);
		child_free(data);
		exit(2);
	}
}

void	child(t_data *data, char **argv, char **envp)
{
	data->pid[data->curr_cmd] = fork();
	if (data->pid[data->curr_cmd] < 0)
	{
		close_pipes(data);
		parent_free(data);
		msg_perror_exit("fork");
	}
	else if (data->pid[data->curr_cmd] == 0)
	{
		if (data->curr_cmd == 0)
			set_dup(data->infile_fd, data->pipe[1]);
		else if (data->curr_cmd == data->cmd_nbr - 1)
			set_dup(data->pipe[2 * data->curr_cmd - 2], data->outfile_fd);
		else
			set_dup(data->pipe[2 * data->curr_cmd - 2],
				data->pipe[2 * data->curr_cmd + 1]);
		child_cmd(argv, data);
		close_pipes(data);
		execve(data->cmd, data->cmd_args, envp);
		parent_free(data);
		exit (2);
	}
}
