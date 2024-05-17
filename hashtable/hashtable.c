/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:07:37 by pepie             #+#    #+#             */
/*   Updated: 2024/05/18 00:07:37 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static size_t	hashtable_index(t_hashtable *ht, char *key, size_t size)
{
	size_t	hashed_key;

	hashed_key = ht->hash(key, ft_strlen(key)) % size;
	return (hashed_key);
}

t_hashtable		*hashtable_create(uint32_t size)
{
	t_hashtable	*ht;

	ht = malloc(sizeof(t_hashtable));
	if (!ht)
		return (NULL);
	ht->size = size;
	ht->hash = hash;
	ht->elements = ft_calloc(sizeof(t_entry), size);
	return (ht);
}

void			hashtable_destroy(t_hashtable *ht)
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
			free(entry);
			entry = next;
		}
		i++;
	}
	free(ht->elements);
	free(ht);
}

void			hashtable_print(t_hashtable *ht)
{
	uint32_t	i;
	t_entry		*entry;

	printf("Hashtable:\n");
	i = 0;
	while (i < ht->size)
	{
		entry = ht->elements[i];
		if (entry) {
			printf("\t%i\t--\n", i);
			while (entry)
			{
				printf("\t\t(%s)\t-> %p\n", entry->key, entry->value);
				entry = entry->next;
			}
		}
		else
			printf("\t%i\tNULL\n", i);
		i++;
	}
}

bool		hashtable_insert(t_hashtable *ht, char *key, void *value)
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

void			*hashtable_search(t_hashtable *ht, char *key)
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

void			hashtable_delete(t_hashtable *ht, char *key)
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

int main(void)
{
	t_hashtable	*ht;

	ht = hashtable_create(10);

	//hashtable_insert(ht, "foo", "bar");
	//hashtable_insert(ht, "PATH", );
	hashtable_insert(ht, "2", "baz");
	hashtable_insert(ht, "1", "qux");

	hashtable_print(ht);

	printf("hello -> %s\n", (char *)hashtable_search(ht, "PATH"));
	printf("foo -> %s\n",  (char *)hashtable_search(ht, "HOME"));
	printf("2 -> %s\n",  (char *)hashtable_search(ht, "2"));

	hashtable_destroy(ht);
}