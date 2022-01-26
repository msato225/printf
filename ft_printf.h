#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "printf.h"

int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		n_len(int n);
char	*ft_itoa(int n);
int		ft_tolower(int c);
char	*ft_tolower_all(char *c);
size_t	ft_format_char(int c);
size_t	ft_format_str(char *str);
size_t	ft_format_integer(int i);
size_t	ft_format_unsigned(unsigned long long n);
size_t	ft_format_hex(unsigned long long n, int f);
size_t	ft_format_pointer(unsigned long long p);
int		ft_isdigit(char c);
int		ft_isspace(char c);
size_t	putnbr_base(unsigned long long num, char *base);
int		ft_judge_format(int c, va_list args);
int		ft_count(char *input, va_list args);
int		ft_printf(const char *format, ...);

# define LOWER 0
# define UPPER 1

#endif
