/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:49:16 by pepie             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/14 20:52:52 by pepie            ###   ########.fr       */
=======
/*   Updated: 2024/05/07 11:57:33 by pepie            ###   ########.fr       */
>>>>>>> 6dc9f48 (Fix compile + Add atoi / atol base)
/*                                                                            */
/* ************************************************************************** */

#include "libft_core.h"

int	ft_str_is_num(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char*str)
{
	int	minus_count;
	int	num;

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
