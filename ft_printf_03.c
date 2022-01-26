#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	const char	*p2;

	if (dst == NULL && src == NULL)
		return (NULL);
	p1 = (char *)dst;
	p2 = (const char *)src;
	while (n-- > 0)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len);
	return (copy);
}

int	n_len(int n)
{
	unsigned int	len;
	long			l;

	l = n;
	len = 1;
	if (l < 0)
	{
		l *= -1;
		len++;
	}
	while (l >= 10)
	{
		l = l / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	long	l;

	l = n;
	p = (char *)malloc(sizeof(char) * n_len(n) + 1);
	if (p == NULL)
		return (NULL);
	i = n_len(n);
	if (l < 0)
	{
		l *= -1;
		p[0] = '-';
	}
	p[i] = '\0';
	while (i-- > 0)
	{
		if (p[i] == '-')
			break ;
		p[i] = '0' + (l % 10);
		l = l / 10;
	}
	return (p);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}
