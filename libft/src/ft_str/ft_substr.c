/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:25:09 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 11:15:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	size;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	size = len + 1;
	sub = (char *) malloc(size * sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

// static void	allocate(size_t i, size_t len, unsigned int start, char **str)
// {
// 	if (start > i)
// 	{
// 		*str = (char *)malloc (sizeof(char));
// 		**str = '\0';
// 	}
// 	else if (i - start > len)
// 		*str = (char *)malloc (sizeof(char) * (len + 1));
// 	else
// 		*str = (char *)malloc (sizeof(char) * (i - start + 1));
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*str;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	allocate(i, len, start, &str);
// 	if (!str)
// 		return (NULL);
// 	i = (size_t) start;
// 	while (i - start < len && s[i])
// 	{
// 		str[i - start] = s[i];
// 		i++;
// 	}
// 	str[i - start] = '\0';
// 	return (str);
// }
// int main()
// {
//     // char	str[] = "lorem ipsum dolor sit amet";
//     printf("%s\n", ft_substr("tripouille", 0, 42000));
//     // printf("%s\n", ft_substr(str, 7, 10));
//     // printf("%s\n", ft_substr(str, 7, 0));
//     // printf("%s\n", ft_substr(str, 0, 0));
//     // printf("%s\n", ft_substr(str, 400, 20));
// }
