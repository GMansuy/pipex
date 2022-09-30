/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:30:31 by gmansuy           #+#    #+#             */
/*   Updated: 2022/05/11 10:48:03 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;
	size_t	i;

	tmp_s = (char *) src;
	tmp_d = (char *) dest;
	i = n;
	if (tmp_d < tmp_s)
	{
		while (i--)
			*tmp_d++ = *tmp_s++;
	}
	else
	{
		while (i--)
		{
			*(tmp_d + i) = *(tmp_s + i);
		}
	}
	return (dest);
}

/*int main()
  {
  char s[] = "123456789";
  char d[] = "abcdef";

  printf("%s\n", s);
  printf("%s\n", d);
  printf("\n");

// memmove(d, s, 4);
// printf("%s\n", s);
// printf("%s\n", d);
// printf("\n");

ft_memmove(d, s, 4);
printf("%s\n", s);
printf("%s\n", d);
printf("\n");

}
 */
