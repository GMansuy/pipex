/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 18:53:59 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *) s;
	while (*tmp_s)
	{
		if (*tmp_s == (unsigned char)c)
			return ((char *)tmp_s);
		tmp_s++;
	}
	if (c != 0)
		return (NULL);
	else
		return ((char *) tmp_s);
}

// int main()
// {
// 	printf("%s\n", ft_strchr("bonsoir", 'n'));
// 	printf("%p\n", ft_strchr("bonsoir", 'p'));
// }
