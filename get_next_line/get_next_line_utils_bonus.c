/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polepie <polepie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:06:18 by pepie             #+#    #+#             */
/*   Updated: 2024/03/06 14:56:18 by polepie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_freeman(t_gnl *gnl, char *ret)
{
	t_list	*elem;
	t_list	*next;

	elem = *(gnl->list);
	while (elem)
	{
		next = elem->next;
		free(elem->content);
		free(elem);
		elem = next;
	}
	free(gnl->buf);
	free(gnl->list);
	free(gnl);
	return (ret);
}

void	ft_lstadd_back_gnl(t_list **lst, char *new_content)
{
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = ft_strndup(new_content, ft_strlen(new_content));
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
	{
		last = last->next;
	}
	if (last == NULL)
		return ;
	last->next = new;
}

int	ft_lstiter(void *lst, int (*f)(char *), bool type)
{
	int	i;

	if (type == 0)
	{
		i = 0;
		while (lst != NULL)
		{
			i += f(((t_list *)lst)->content);
			(lst) = ((t_list *)lst)->next;
		}
		return (i);
	}
	else
	{
		((t_gnl *)lst)->list = malloc(sizeof(t_list *));
		if (!((t_gnl *)lst)->list)
			return (1);
		(*((t_gnl *)lst)->list) = NULL;
		((t_gnl *)lst)->buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!((t_gnl *)lst)->buf)
			return (1);
		return (0);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *src, int nb)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (nb + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
