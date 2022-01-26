#include "ft_printf.h"

size_t	ft_format_pointer(unsigned long long p)
{
	size_t	n;

	n = ft_putstr("0x");
	n += putnbr_base(p, "0123456789abcdef");
	return (n);
}

size_t	putnbr_base(unsigned long long num, char *base)
{
	unsigned long long	e;
	unsigned long long	output;
	size_t				ret;
	size_t				len;

	ret = 0;
	e = 1;
	len = ft_strlen(base);
	while (num >= e)
		e *= len;
	e /= len;
	while (e > 1)
	{
		output = (num / e);
		ret += write(1, &base[output % len], 1);
		e /= len;
	}
	ret += write(1, &base[num % len], 1);
	return (ret);
}

int	ft_judge_format(int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n += ft_format_char(va_arg(args, int));
	else if (c == 's')
		n += ft_format_str(va_arg(args, char *));
	else if (c == 'p')
		n += ft_format_pointer((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		n += ft_format_integer(va_arg(args, int));
	else if (c == 'u')
		n += ft_format_unsigned((unsigned)va_arg(args, unsigned));
	else if (c == 'x')
		n += ft_format_hex(va_arg(args, unsigned), LOWER);
	else if (c == 'X')
		n += ft_format_hex(va_arg(args, unsigned), UPPER);
	else if (c == '%')
		n += ft_putstr("%");
	return (n);
}

int	ft_count(char *input, va_list args)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			count += ft_judge_format(input[i], args);
		}
		else
		{
			ft_putchar(input[i]);
			count++;
		}
		i++;
		if (!input[i])
			return (count);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	char	*input;
	int		res;
	va_list	args;

	input = ft_strdup(format);
	if (!input)
		return (0);
	res = 0;
	va_start(args, format);
	res = ft_count(input, args);
	va_end(args);
	free(input);
	return (res);
}
