/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:24:06 by manki             #+#    #+#             */
/*   Updated: 2019/08/01 17:20:35 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBFT_H
# define MYLIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define LDB_E_START 1
# define LDB_E_END 15
# define LDB_M_START 16
# define LDB_M_END 127 - 48
# define LDB_E_BIAS 16383
# define LDB_BUF sizeof(long double)

# define E_START 1
# define E_END 11
# define M_START 12
# define M_END 63
# define E_BIAS 1023
# define BUF sizeof(double)

# define MINUS 0b00000001
# define PLUS 0b00000010
# define ZERO 0b00000100
# define SPACE 0b00001000
# define HASH 0b00010000
# define POINT 0b00100000

# define H_POURCENT 0b00000001
# define HH_U 0b00000010
# define L_O 0b00000100
# define LL_X 0b00001000
# define LD_X 0b00010000

typedef struct		s_define
{
	short			e_start;
	short			e_end;
	short			m_start;
	short			m_end;
	short			e_bias;
	short			buf;
	long double		b;
	double			a;
}					t_define;

typedef unsigned char	t_byte;

typedef struct		s_option
{
	t_byte	flag;
	t_byte	option;
	t_byte	modif;
	int		width;
	int		precision;
}					t_option;

typedef char		*(*t_ft_conv)(t_option, va_list *, size_t *size);

typedef struct		s_conv
{
	char			*c;
	t_ft_conv		fun;
}					t_conv;

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_coord
{
	int				i;
	int				j;
}					t_coord;

int					ft_printf(const char *restrict format, ...);

int					ft_is_conv(char c);
char				*ft_conv(char **p, va_list *ap, size_t *size);

int					ft_unblen_base(unsigned long long n, char *base);
void				ft_tr(char *s, char old, char neww);
char				*ft_charcat(char c, char *str, int len);
char				*ft_bischarcat(char a, char b, char *str, int len);
char				*ft_strpower(char *nb, int nb_len, int power);

void				ft_add_bit(t_byte *tab, t_byte bit, t_byte at);
t_byte				ft_read(t_byte tab[], t_byte at);
t_byte				ft_fill_opt(t_byte *dst, char src, char tab[]);

char				*ft_fill_c_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_di_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_p_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_s_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_uoxx_output(t_option opt, va_list *ap, size_t *s);
char				*ft_fill_f_output(t_option opt, va_list *ap, size_t *size);

void				ft_setvar(t_define *var, int ldb, long double b, double a);
char				*ft_dbl_to_str(t_define var);

char				*ft_get_fvalue(t_option opt, char f_str[], t_define var);

t_list				*ft_lstnew(char *content, size_t content_size);
void				ft_lsadd(t_list **list, char *content, size_t c_size);
int					ft_lstlen(t_list *list);
size_t				ft_lst_content_size(t_list *list);
size_t				ft_lstprint(t_list list[]);

void				ft_init_option(t_option *opt);
void				ft_fill_t_option(t_option *opt, char **p);
char				*ft_what_base(t_option opt);

char				*ft_putdot(char *str, size_t str_len, int position);

char				*ft_roundd(char *nb, int pos, int *dot_pos, int precision);

t_byte				ft_is_max(char *bit_nb, int from, int to);
t_byte				ft_is_null(char *bit_nb, int from, int to);
char				*ft_mul2_traduct(char *nb, int i, int end, t_define var);
char				*ft_newtrad(char *f_str, int index, int i, int len);

char				*ft_stradd(char *a, char *b, size_t a_len, size_t b_len);
char				*ft_leftadd(char *a, char *b, size_t a_len, size_t b_len);
char				*ft_strmul(char *a, char *b, size_t a_len, size_t b_len);
char				*ft_strdivby2(char *a, size_t a_len);

char				*ft_ctob(unsigned char *tab, int size);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long n, char base[]);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ulltoa_base(unsigned long long n, char base[]);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_realloc(void *ptr, size_t size);
int					ft_dbl_len(long double nb);
size_t				ft_max(size_t a, size_t b);
void				ft_lstdel(t_list **alst);

# define BUFF_SIZE 32
# define FD 42000

typedef struct		s_gnl
{
	int				i;
	int				r;
	char			buf[BUFF_SIZE];
	int				len;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_list_push_front(t_list **l, char *c, size_t c_size);
void				ft_list_push_back(t_list **l, char *c, size_t c_size);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, size_t l);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const*s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_strrev(char *str);
void				ft_sort_integer_table(int *tab,int size);
void				ft_sort_wordtab(char **tab);
void				ft_print_words_tables(char **tab, char c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_str_is_alpha(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strcapitalize(char *str);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strcasestr(const char *haystack, const char *needle);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strndup(const char *s1, size_t n);
void				ft_putnbr_base(int nbr, char *base);
int					ft_sqrt(int nb);
int					ft_abs(int nb);
int					ft_isprime(unsigned int nb);
void				t_strmap(char const *s, char (*f)(char));

#endif
