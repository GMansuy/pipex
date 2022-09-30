/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:46:37 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 11:27:08 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tab_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len ++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*fill_tab(char *str, unsigned int n, int neg, int *i)
{
	if (neg)
	{
		str[*i] = '-';
		neg = 0;
		(*i)++;
	}
	if (n > 9)
	{
		fill_tab(str, n / 10, neg, i);
		fill_tab(str, n % 10, neg, i);
	}
	else
	{
		str[*i] = n + '0';
		(*i)++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				len;
	int				i;
	unsigned int	convert;
	char			*str;

	len = tab_len(n);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		convert = (unsigned int)(n * -1);
	else
		convert = (unsigned int) n;
	i = 0;
	str = fill_tab(str, convert, n < 0, &i);
	return (str);
}
// int main()
// {
//     char *str;

//     // int entier = 435;
//     // str = ft_itoa(entier);
//     // printf("ITOA %d : %s\n", entier, str);

//     // int neg = -435;
//     // str = ft_itoa(neg);
//     // printf("ITOA %d : %s\n", neg, str);

//     int max = 2147483647;
//     str = ft_itoa(max);
//     printf("ITOA %d : %s\n", max, str);

//     // int min = -2147483648;
//     // str = ft_itoa(min);
//     // printf("%s", str);

//     // int nul = 0;
//     // str = ft_itoa(nul);
//     // printf("ITOA %d : %s\n", nul, str);

//     free(str);
// }
