/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:41:27 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 20:39:21 by sgadinga         ###   ########.fr       */
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

# ifndef FLT_MAX
#  define FLT_MAX 3.402823466e+38F
# endif
# ifndef FLT_MIN
#  define FLT_MIN 1.17549435E-38F
# endif
# ifndef DBL_MAX
#  define DBL_MAX 1.79769e+308
# endif

typedef enum e_error_type
{
	ERR_RUNTIME,
	ERR_SYNTAX,
	ERR_WARNING,
	ERR_NONE
}					t_error_type;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}					t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_bool				ft_isascii(int c);
t_bool				ft_isdigit(int c);
t_bool				ft_isalnum(int c);
t_bool				ft_isalpha(int c);
t_bool				ft_isupper(int c);
t_bool				ft_islower(int c);
t_bool				ft_isspace(int c);
t_bool				ft_isprint(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_atoi(const char *s);
int					ft_max(const int a, const int b);
int					ft_min(const int a, const int b);

float				ft_strtof(const char *nptr, char **endptr);
double				ft_strtod(const char *nptr, char **endptr);
long				ft_strtol(const char *nptr, char **endptr, int base);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);
void				log_error(t_error_type type, const char *base,
						const char *format, ...);

char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_split(const char *s, int c);
char				*ft_strtrim(const char *s, const char *set);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_vstrjoin(unsigned int n, char *sep, ...);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strstrip(const char *s, const char *set,
						char ***leftover);
char				*get_next_line(int fd);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t n, size_t size);
void                *ft_realloc(void *ptr, size_t old_size, size_t new_size);
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
size_t				ft_strcspn(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
