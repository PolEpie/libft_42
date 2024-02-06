/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polepie <polepie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:50:07 by pepie             #+#    #+#             */
/*   Updated: 2024/02/05 21:31:02 by polepie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int nb)
{
	int		i;
	char	*retun;

	i = ft_strlen((char *)src);
	retun = malloc(sizeof(char) * (i + 1));
	if (!retun)
		return (NULL);
	*retun = '\0';
	if (i == 1)
		return (retun);
	while (i >= 0 && i > (i - nb))
	{
		retun[i] = src[i];
		i--;
	}
	return (retun);
}
