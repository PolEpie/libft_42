/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polepie <polepie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:42:39 by pepie             #+#    #+#             */
/*   Updated: 2024/02/05 21:25:22 by polepie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_gnl {
	t_list		**list;
	char		*buf;
}	t_gnl;

enum e_verif_nl {
	WITHOUT_I,
	WITH_I,
	FRAUD_NORM
};

char	*get_next_line(int fd);

void	ft_lstadd_back_create(t_list **lst, char *n);
int		ft_lstiter_sum(void *lst, unsigned long  (*f)(char *));
char	*ft_strndup(char *src, int nb);
char	*ft_freeman(t_gnl *gnl, char *ret);
int		init_gnl(t_gnl *gnl);

#endif