/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:53:33 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 18:53:17 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp_s1;
	unsigned char		*tmp_s2;

	if (s1 == s2 || n == 0)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		if (n)
		{
			tmp_s1++;
			tmp_s2++;
		}
	}
	return (0);
}

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	unsigned char		*tmp_s1;
// 	unsigned char		*tmp_s2;
// 	size_t				i;

// 	tmp_s2 = (unsigned char *) s2;
// 	tmp_s1 = (unsigned char *) s1;
// 	i = 0;
// 	while ((tmp_s1[i] || tmp_s2[i]) && (i < n))
// 	{
// 		if (tmp_s1[i] == tmp_s2[i])
// 			i++;
// 		else
// 			return (tmp_s1[i] - tmp_s2[i]);
// 	}
// 	return (0);
// }

// int main()
// {
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};

// 	printf("%d\n", ft_memcmp(s2, s3, 4));
// }
