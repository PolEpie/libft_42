/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:58:28 by pepie             #+#    #+#             */
/*   Updated: 2024/05/23 02:50:09 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_itoa_len(int n)
{
	unsigned int	nbr;
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

void	ft_itoa_recur(int n, char *str)
{
	unsigned int	nbr;
	char			c[2];

	nbr = n;
	c[1] = '\0';
	if (n < 0)
	{
		ft_strcat(str, "-");
		nbr = n * -1;
	}
	if (nbr >= 10)
		ft_itoa_recur(nbr / 10, str);
	c[0] = '0' + (nbr % 10);
	ft_strcat(str, c);
}

char	*ft_itoa(int n)
{
	char			*resp;

	resp = malloc(sizeof(char) * (get_itoa_len(n) + 1));
	if (!resp)
		return (NULL);
	*resp = 0;
	ft_itoa_recur(n, resp);
	return (resp);
}
