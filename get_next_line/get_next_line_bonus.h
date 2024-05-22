/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:42:39 by pepie             #+#    #+#             */
/*   Updated: 2024/05/22 16:58:25 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

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

void	ft_lstadd_back_gnl(t_list **lst, char *n);
int		ft_strlen(char *str);
char	*ft_strndup(const char *src, int n);
int		ft_lstiter(void *lst, int (*f)(char *), bool type);
char	*ft_freeman(t_gnl *gnl, char *ret);

#endif