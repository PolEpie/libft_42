/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:15:16 by pepie             #+#    #+#             */
/*   Updated: 2024/05/22 16:57:48 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CORE_H
# define LIBFT_CORE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

unsigned long	ft_strlen(char *str);

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

char			*ft_strjoin(char const *s1, char const *s2);

int				ft_memcmp(const void *pt1, const void *pt2, size_t size);

unsigned int	ft_strcmp(char*s1, char*s2);
unsigned int	ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(char *str, char *to_find, size_t len);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);

int				ft_mathmin(int a, int b);
int				ft_mathmax(int a, int b);
int				ft_math_abs(int num);

void			*ft_calloc(size_t nitems, size_t size);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
void			ft_freesplit(char **split);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_str_is_num(char str);
int				ft_str_is_whitespace(char str);

//Bonus
t_list			*ft_lstnew(void *content);
t_list			*ft_lstadd_front(t_list **lst, t_list *n);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *n);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));

int				ft_atoi_base(char *str, char *base);
long			ft_atol_base(char *str, char *base);

#endif
