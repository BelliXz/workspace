# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		ft_putchar(n + '0', count);
	}
}

void	ft_puthexl(int n, int *count)
{
	char			*hex;
	unsigned int	num;

	hex = "0123456789abcdef";
	num = n;
	if (num == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (num < 16)
		ft_putchar(hex[num], count);
	else
	{
		ft_puthexl(num / 16, count);
		ft_putchar(hex[num % 16], count);
	}
}

static void	handle_format(va_list args, char format, int *count)
{
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'x')
		ft_puthexl(va_arg(args, int), count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			handle_format(args, str[i + 1], &count);
			i += 2;
		}
		else
		{
			ft_putchar(str[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
