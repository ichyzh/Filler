/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:52:38 by ichyzh            #+#    #+#             */
/*   Updated: 2017/12/15 17:52:51 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define BUFF_SIZE 1
# include <fcntl.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_glist
{
	int				fd;
	char			*str;
	struct s_glist	*next;
}					t_glist;

int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *nb);
size_t				ft_get_int_len(int n);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
int					ft_word_count(const char *s, char d);
char				**ft_strsplit(char const *s, char d);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t l);
char				*ft_strnew(size_t size);
char				*ft_strn_char_new(ssize_t size, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
void				ft_putstr(char const *s);
void				ft_putchar(char ch);
void				ft_putendl(char const *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
void				ft_bzero(void *s, size_t n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_lstsize(t_list *begin_list);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
