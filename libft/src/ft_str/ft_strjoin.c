/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:58:51 by gmansuy           #+#    #+#             */
/*   Updated: 2022/09/22 17:15:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_concat(char **str, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		(*str)[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		(*str)[i] = s2[j];
		i++;
		j++;
	}
	(*str)[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(*s1))
		return (ft_strdup(s2));
	if (!(*s2))
		return (ft_strdup(s1));
	len_1 = 0;
	len_2 = 0;
	while (s1[len_1])
		len_1++;
	while (s2[len_2])
		len_2++;
	str = (char *)malloc (sizeof(char) * (len_1 + len_2 + 1));
	if (!str)
		return (NULL);
	str_concat(&str, s1, s2);
	return (str);
}
