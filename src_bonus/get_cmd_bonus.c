/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:47:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/22 16:55:32 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_path(char **envp)
{
	if (!envp && !*envp)
		return (NULL);
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!*envp)
		return (NULL);
	return (*envp + 5);
}

int	get_cmd_paths(char **envp, t_data *data)
{
	data->env_path = get_path(envp);
	if (!data->env_path)
		return (data->cmd_paths = NULL, 0);
	data->cmd_paths = ft_split(data->env_path, ':');
	if (!data->cmd_paths)
	{
		free(data->env_path);
		pipe_free(data);
	}
	return (1);
}
