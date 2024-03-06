/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polepie <polepie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:05:19 by pepie             #+#    #+#             */
/*   Updated: 2024/03/06 13:59:29 by polepie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlen(char *str)
{
	int	len;

	len = 0;
    if (!str)
        return (0);
	while (str[len])
		len++;
	return (len);
}
