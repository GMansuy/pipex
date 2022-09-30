/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:11:58 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 18:52:57 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size > 0)
	{
		while ((src[i]) && --size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main()
// {
// 	char src[] = "lolololololoololo";
// 	char dest[] = "xaxaxaxaxaxaxax";
// 	int i;
// 	i = (int) ft_strlcpy();
// 	printf("%d\n", i);
// }
