/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:53:05 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/30 09:17:40 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct s_data
{
	int		id;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		infile_fd;
	int		outfile_fd;
	int		is_heredoc;
	int		*pid;
	int		cmd_nbr;
	int		pipe_nbr;
	int		*pipe;
	int		curr_cmd;
}	t_data;

void	init_data(t_data *data);
// get
int		get_heredoc(char *arg, t_data *data);
int		get_cmd_paths(char **envp, t_data *data);
void	get_in(char **argv, t_data *data);
void	get_out(char *argv, t_data *data);

// pipes
void	close_pipes(t_data *data);
void	init_pipes(t_data *data);
void	init_err_pipes(t_data *data);

// child
void	child(t_data *data, char **argv, char **envp);
// free
void	parent_free(t_data *data);
void	child_free(t_data *data);
void	pipe_free(t_data *data);
// error
void	msg_perror_exit(char *err);
void	msg_pipe(char *arg);
int		error_msg(char *err);
// heredoc
void	heredoc(char *argv, t_data *data);

#endif