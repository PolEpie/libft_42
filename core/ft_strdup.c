/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:50:07 by pepie             #+#    #+#             */
/*   Updated: 2024/09/24 12:28:56 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*retun;

	if (!src)
		return (NULL);
	len = ft_strlen((char *)src) + 1;
	retun = malloc(sizeof(char) * len);
	if (!retun)
		return (NULL);
	retun[len - 1] = '\0';
	i = 0;
	while (src[i] && i < len)
	{
		retun[i] = src[i];
		i++;
	}
	return (retun);
}
