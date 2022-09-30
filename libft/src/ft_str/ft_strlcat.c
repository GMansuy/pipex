/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:11:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 11:32:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	size_dst;
	unsigned int	size_src;
	unsigned int	i;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	i = 0;
	if (size <= size_dst)
		return (size + size_src);
	while (src[i] && (size_dst + i) < size - 1)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}

// int main()
// {
// 		char *dest;

// 		dest = (char *) malloc (sizeof(*dest) * 15);
// 		memset(dest, 0, 15);
// 		memset(dest, 'r', 6);

// 		memset(dest, 'r', 15);
// 		printf("%d\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 		// write(1, "\n", 1);
// 		write(1, dest, 15);
// }
