/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:50:07 by pepie             #+#    #+#             */
/*   Updated: 2024/05/23 03:18:08 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*retun;

	i = ft_strlen((char *)src) + 1;
	retun = malloc(sizeof(char) * i);
	if (!retun)
		return (NULL);
	while (i >= 0)
	{
		retun[i] = src[i];
		i--;
	}
	return (retun);
}
