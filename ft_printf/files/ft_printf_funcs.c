#include "../ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int		len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

int	ft_putnumb(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
