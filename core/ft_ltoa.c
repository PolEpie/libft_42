/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:11:10 by Sifex             #+#    #+#             */
/*   Updated: 2025/02/04 15:21:04 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	get_ltoa_len(long n)
{
	unsigned long	nbr;
	int				len;

	nbr = n;
	len = 0;
	if (n < 0)
	{
		nbr = n * -1;
		len++;
	}
	while (nbr / 10)
	{
		len++;
		nbr /= 10;
	}
	return (len + 1);
}

void	ft_ltoa_recur(long n, char *str)
{
	unsigned long	nbr;
	char			c[2];

	nbr = n;
	c[1] = '\0';
	if (n < 0)
	{
		ft_strcat(str, "-");
		nbr = n * -1;
	}
	if (nbr >= 10)
		ft_ltoa_recur(nbr / 10, str);
	c[0] = '0' + (nbr % 10);
	ft_strcat(str, c);
}

char	*ft_ltoa(long n)
{
	char	*resp;

	resp = malloc(sizeof(char) * (get_ltoa_len(n) + 1));
	if (!resp)
		return (NULL);
	*resp = 0;
	ft_ltoa_recur(n, resp);
	return (resp);
}
