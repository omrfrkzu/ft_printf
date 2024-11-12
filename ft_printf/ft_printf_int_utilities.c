#include "ft_printf.h"

int	ft_putptr(uintptr_t n, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= (uintptr_t)base_len)
	{
		count += ft_putptr(n / base_len, base);
		count += ft_putptr(n % base_len, base);
	}
	else
		count += ft_putchar(base[n % base_len]);
	return (count);
}

int	ft_unsnd_putnbr_base(unsigned int nbr, char *base)
{
	int	count;
	int	base_len;
	int	tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned int)base_len)
	{
		tmp = ft_unsnd_putnbr_base(nbr / base_len, base);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar(base[nbr % base_len]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(int nb)
{
	int		count;
	long	number;
	int		tmp;

	count = 0;
	number = nb;
	if (nb < 0)
	{
		number *= -1;
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
	}
	if (number >= 10)
	{
		tmp = ft_putnbr(number / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar(number % 10 + '0') == -1)
		return (-1);
	return (++count);
}

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}
