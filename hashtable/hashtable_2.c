/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:13:47 by pepie             #+#    #+#             */
/*   Updated: 2024/05/18 01:13:47 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static size_t	hashtable_index(t_hashtable *ht, char *key, size_t size)
{
	size_t	hashed_key;

	hashed_key = ht->hash(key, ft_strlen(key)) % size;
	return (hashed_key);
}

bool	hashtable_insert(t_hashtable *ht, char *key, void *value)
{
	t_entry		*entry;
	size_t		index;

	if (key == NULL || value == NULL || ht == NULL)
		return (false);
	index = hashtable_index(ht, key, ht->size);
	if (hashtable_search(ht, key) != NULL)
		return (false);
	entry = malloc(sizeof(*entry));
	if (!entry)
		return (false);
	entry->key = ft_strdup(key);
	if (!entry->key)
		return (free(entry), false);
	entry->value = value;
	entry->next = ht->elements[index];
	ht->elements[index] = entry;
	return (true);
}

void	*hashtable_search(t_hashtable *ht, char *key)
{
	t_entry		*entry;
	size_t		index;

	if (key == NULL || ht == NULL)
		return (NULL);
	index = hashtable_index(ht, key, ht->size);
	entry = ht->elements[index];
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}

void	hashtable_delete(t_hashtable *ht, char *key)
{
	t_entry		*entry;
	t_entry		*prev;
	size_t		index;

	if (key == NULL || ht == NULL)
		return ;
	index = hashtable_index(ht, key, ht->size);
	entry = ht->elements[index];
	prev = NULL;
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
		{
			if (prev)
				prev->next = entry->next;
			else
				ht->elements[index] = entry->next;
			free(entry->key);
			free(entry);
			return ;
		}
		prev = entry;
		entry = entry->next;
	}
}
