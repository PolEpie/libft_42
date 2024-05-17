/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:09:18 by pepie             #+#    #+#             */
/*   Updated: 2024/05/18 00:09:18 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "libft_core.h"

# define HASHTABLE_SIZE 256

typedef struct s_entry {
	char			*key;
	size_t			size;
	void			*value;
	struct s_entry	*next;
}	t_entry;

typedef uint64_t	(*t_hashfunction)(char *name, size_t size);

typedef struct s_hashtable {
	size_t			size;
	t_hashfunction	hash;
	t_entry			**elements;
}	t_hashtable;

t_hashtable		*hashtable_create(uint32_t size);
void			hashtable_destroy(t_hashtable *hashtable);
bool			hashtable_insert(t_hashtable *hashtable, char *key, void *v);
void			*hashtable_search(t_hashtable *hashtable, char *key);
void			hashtable_delete(t_hashtable *hashtable, char *key);

#endif