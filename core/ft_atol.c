/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:49:16 by pepie             #+#    #+#             */
/*   Updated: 2024/05/14 20:52:57 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_core.h"

long	ft_atol(const char*str)
{
	int		minus_count;
	long	num;

	num = 0;
	minus_count = 0;
	while (ft_str_is_whitespace(*str))
	str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (ft_str_is_num(*str))
	{
		num = num * 10;
		num = num + *str - '0';
		str++;
	}
	if (minus_count % 2 == 1)
		num = num * -1;
	return (num);
}
