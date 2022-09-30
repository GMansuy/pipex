/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:44:56 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 11:03:58 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char    f(unsigned int i, char c)
// {
//     c += i;
//     return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	str = (char *) malloc (sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

// int main()
// {
//     char *str;

//     str = ft_strmapi("salut", &f);
//     printf("%s", str);
// }
