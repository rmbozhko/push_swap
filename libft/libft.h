/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:53:46 by rbozhko           #+#    #+#             */
/*   Updated: 2018/07/28 18:42:09 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>

# define MEMORY_COEF 5
# define BUFF_SIZE 1
# define NL_CODE ft_strchr(temp, '\n')
# define S_C_SUB (NL_CODE - temp)
# define IF_FP ((fd < 0 || fd > 4096) || ((read(fd, buff, 0)) == -1 && !(head)))
# define IF_SP (!(line) || !(ft_memset(buff, 0, BUFF_SIZE + 1)))

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef	struct	s_node
{
	int				fd;
	char			*str;
	struct s_node	*next;
}				t_node;

size_t			ft_abs(const int n);
void			ft_print_iarr(int *arr, const size_t len);
char			*ft_reverse_str(char *str);
int				ft_skip_whitespaces(char *str, int i);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t num);
void			*ft_memchr(const void *str, int c, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t num);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *src, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void(*f)(char*));
void			ft_striteri(char *s, void(*f)(unsigned int, char*));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_numlen(int n);
int				ft_is_whitespace(char c);
int				ft_isspace(char c);
int				ft_words_count(const char *s, char c);
int				ft_wordlen(const char *s, char c);
char			**ft_strsplit(const char *s, char c);
void			ft_intswap(int *ar1, int *ar2);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
int				ft_is_numeric(const char *str);
void			ft_putbidstr(char **arr);
size_t			ft_bidlen(char **arr);
intmax_t		ft_atoi_base(char *str, int base);
void			ft_countdown(int end);
int				ft_bid_findstr(char *room, char **temp);
char			**ft_create_bid_arr(size_t size, char *str);
size_t			ft_count_char(char *str, char c);
size_t			ft_find_smallest(const int *arr, const size_t arr_size);
size_t			ft_find_biggest(const int *arr, const size_t arr_size);
void			ft_free_bidarr(char **arr, size_t len);
char			*ft_lstrip(char *str);
char			*ft_rstrip(char *str);
char			*ft_strip(char *str);
char			**ft_read_file(const int fd, char **arr);
void			ft_putnbrendl_fd(int num, int fd);
void			ft_putnbrendl(int num);
void			ft_throw_exception(const char *str);
bool			ft_is_int(const char *str);
char			*ft_bidarrjoin(char **arr, const size_t len);
size_t			ft_omit_whitespaces(const char *str, size_t i);
bool			ft_is_sorted(const int *arr, const size_t len);
int				get_next_line(const int fd, char **line, char *str);
#endif
