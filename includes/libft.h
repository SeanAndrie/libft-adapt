/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:41:27 by sgadinga          #+#    #+#             */
/*   Updated: 2025/09/25 14:48:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

typedef enum e_error_type
{
	ERROR_SYNTAX,
	ERROR_RUNTIME
}		t_error_type;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);

int					ft_atoi(const char *s);
int 				ft_count_char(const char *str, char c);
long				ft_strtol(const char *nptr, char **endptr, int base);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);
void				log_error(t_error_type type, const char *format, ...);

char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				**ft_split(const char *s, int c);
char				*ft_strtrim(const char *s, const char *set);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_vstrjoin(unsigned int n, char *sep, ...);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_substr_range(const char *s, size_t start, size_t end);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t n, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_putnbr_fd(int n, int fd);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putendl_fd(char *s, int fd);

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
