/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:33:25 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/03 12:09:00 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *) s;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}
/*
int main()
{

    char s[] = "bateau";

    ft_bzero(s, 6);

    printf("%s\n", s + 5);

}*/
