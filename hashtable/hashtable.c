/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:07:37 by pepie             #+#    #+#             */
/*   Updated: 2024/10/03 11:40:46 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashtable.h"

uint64_t	hash(char *name, size_t size)
{
	uint64_t	hash;
	size_t		i;

	hash = 0;
	i = 0;
	while (i < size)
	{
		hash += name[i];
		hash = (hash * name[i]);
		i++;
	}
	return (hash);
}

t_ht	*hashtable_create(uint32_t size)
{
	t_ht	*ht;

	ht = malloc(sizeof(t_ht));
	if (!ht)
		return (NULL);
	ht->size = size;
	ht->hash = hash;
	ht->elements = ft_calloc(sizeof(t_entry), size);
	return (ht);
}

void	hashtable_destroy(t_ht *ht)
{
	uint32_t	i;
	t_entry		*entry;
	t_entry		*next;

	i = 0;
	while (i < ht->size)
	{
		entry = ht->elements[i];
		while (entry)
		{
			next = entry->next;
			free(entry->key);
			if (entry->value)
				free(entry->value);
			free(entry);
			entry = next;
		}
		i++;
	}
	free(ht->elements);
	free(ht);
}

void	hashtable_print(t_ht *ht)
{
	uint32_t	i;
	t_entry		*entry;

	ft_printf("Hashtable:\n");
	i = 0;
	while (i < ht->size)
	{
		entry = ht->elements[i];
		if (entry)
		{
			ft_printf("\t%i\t--\n", i);
			while (entry)
			{
				ft_printf("\t\t(%s)\t-> %p\n", entry->key, entry->value);
				entry = entry->next;
			}
		}
		else
			ft_printf("\t%i\tNULL\n", i);
		i++;
	}
}
