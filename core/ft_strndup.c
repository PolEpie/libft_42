/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:50:07 by pepie             #+#    #+#             */
/*   Updated: 2024/09/24 13:59:07 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int nb)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	if (nb < 0)
		return (NULL);
	size = ft_strlen((char *)src);
	if (size < nb)
		nb = size;
	dest = malloc(sizeof(char) * (nb + 1));
	if (!dest)
		return (NULL);
	while (i < nb)
	{
		if (src[i])
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
