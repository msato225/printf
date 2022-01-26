#include "ft_printf.h"

size_t	ft_format_char(int c)
{
	return (write(1, &c, sizeof(char)));
}

size_t	ft_format_str(char *str)
{
	size_t	res;

	if (!str)
		str = "(null)";
	res = 0;
	while (*str)
	{
		res += ft_putchar(*str);
		str++;
	}
	return (res);
}

size_t	ft_format_integer(int i)
{
	char	*str;
	size_t	n;

	str = ft_itoa(i);
	n = ft_putstr(str);
	free(str);
	return (n);
}

size_t	ft_format_unsigned(unsigned long long n)
{
	size_t	len;

	len = putnbr_base(n, "0123456789");
	return (len);
}

size_t	ft_format_hex(unsigned long long n, int f)
{
	size_t	len;

	if (f == LOWER)
		len = (putnbr_base(n, "0123456789abcdef"));
	if (f == UPPER)
		len = (putnbr_base(n, "0123456789ABCDEF"));
	return (len);
}
