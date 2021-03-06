/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:27:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/16 17:24:25 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void			*ft_bzero(void *dest, size_t size);
void			*ft_memccpy(void *dest,
							const void *src,
							int check,
							size_t size);
void			*ft_memchr(void *dest, int find_char, size_t size);
int				ft_memcmp(const void *dest, const void *src, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memset(void *dest, int fill_char, size_t size);
size_t			ft_strlen(const char *dest);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *dest, int check);
char			*ft_strrchr(const char *dest, int check);
char			*ft_strnstr(const char *dest, const char *src, size_t size);
int				ft_strncmp(const char *dest, const char *src, size_t size);
int				ft_atoi(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_calloc(size_t nelem, size_t elsize);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(int data);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(int));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(int));

t_list			*ft_lstmap(t_list *lst,
							void *(*f)(int),
							void (*del)(void *));

#endif
