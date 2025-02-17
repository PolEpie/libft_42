/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:09:18 by pepie             #+#    #+#             */
/*   Updated: 2024/09/24 12:42:03 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "libft_core.h"

# define HASHTABLE_SIZE 512

typedef struct s_entry {
	char			*key;
	size_t			size;
	void			*value;
	struct s_entry	*next;
}	t_entry;

typedef uint64_t	(*t_hashfunction)(char *name, size_t size);

typedef struct s_ht {
	size_t			size;
	t_hashfunction	hash;
	t_entry			**elements;
}	t_ht;

t_ht		*hashtable_create(uint32_t size);
void		hashtable_destroy(t_ht *hashtable);
bool		ht_insert(t_ht *hashtable, char *key, void *v);
void		*ht_search(t_ht *hashtable, char *key);
void		ht_delete(t_ht *hashtable, char *key);
void		ht_deletef(t_ht *hashtable, char *key);

#endif