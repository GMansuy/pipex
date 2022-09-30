/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:11 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 18:39:08 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	while (n--)
	{
		if (*tmp_s == (unsigned char)c)
			return (tmp_s);
		tmp_s++;
	}
	return (NULL);
}

// int main()
// {
//     char *s = "bonjourno";
// 	// int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

// 	// printf("%s", (char *)ft_memchr(tab, -1, 7));
//     // printf("%s\n", ft_memchr(s, 'j' , 4));
//     // printf("%s\n", ft_memchr(s, 'e' , 2));

// 	printf("%s\n", ft_memchr(s, 2, 3));
// }
