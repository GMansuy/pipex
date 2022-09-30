/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:30:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 19:11:41 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != '\0' && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	ft_strncmp(char *s1, char *s2, unsigned int n)
// {
// 	unsigned char	*str1;
// 	unsigned char	*str2;
// 	unsigned int	i;

// 	str1 = (unsigned char *) s1;
// 	str2 = (unsigned char *) s2;
// 	i = 0;
// 	while ((str1[i] || str2[i]) && (i < n))
// 	{
// 		if (str1[i] == str2[i])
// 			i++;
// 		else
// 			return (str1[i] - str2[i]);
// 	}
// 	return (0);
// }
//int main()
//{
//	printf("%d\n", ft_strncmp("lorem ipsum dolor sit amet", "", 10));
//}
