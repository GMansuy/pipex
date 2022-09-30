/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:11:26 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 10:56:42 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)(s[i]) == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if (c != 0)
		return (NULL);
	else
		return ((char *) s + i);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	*tmp_s;

// 	tmp_s = (unsigned char *) s;
// 	while (*tmp_s)
// 	{
// 		if (*tmp_s == (unsigned char)c)
// 			return ((char* )tmp_s);
// 		tmp_s++;
// 	}
// 	if (*tmp_s != c)
// 		return (NULL);
// 	else
// 		return ((char *) tmp_s);
// }

// int main()
// {
// 	printf("%s\n", ft_strrchr("tripouille", 't'));
// 	printf("%p\n", ft_strrchr("bonsoir", 'p'));
// 	// printf("\n");
// 	// printf("%s\n", strrchr("bonsoir", 's'));
// 	// printf("%p\n", strrchr("bonsoir", 'p'));
// }
