#include "ft_printf.h"
#include <stddef.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;

	va_start(args, format);
	count = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			tmp = format_selector(format[i + 1], args);
			if (tmp == -1)
				return (-1);
			count += tmp;
			i++;
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

int	format_selector(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		uintptr_t	ptr = (uintptr_t)va_arg(args, void*);
		if (ptr == 0)
		{
			ft_putstr("(nil)");
			return (5);
		}
		if (ft_putstr("0x") == -1)
			return (-1);
		return (ft_putptr(ptr, BASE16LOWER) + 2);
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_unsnd_putnbr_base(va_arg(args, unsigned int), BASE10));
	else if (format == 'x')
		return (ft_unsnd_putnbr_base(va_arg(args, unsigned int), BASE16LOWER));
	else if (format == 'X')
		return (ft_unsnd_putnbr_base(va_arg(args, unsigned int), BASE16UPPER));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

#include <stdio.h>
int	main(void)
{
	int		num = 42;
	char	ch = 'A';
	char	*str = "Hello, world!";
	void	*ptr = &num;

	ft_printf("%d\n", num);
	ft_printf("%c\n", ch);
	ft_printf("%s\n", str);
	ft_printf("%p\n", ptr);
	ft_printf("%u\n", (unsigned int)num);
	ft_printf("%x\n", num);
	ft_printf("%X\n", num);
	ft_printf("%%\n\n");

	printf("%d\n", num);
	printf("%c\n", ch);
	printf("%s\n", str);
	printf("%p\n", ptr);
	printf("%u\n", (unsigned int)num);
	printf("%x\n", num);
	printf("%X\n", num);
	printf("%%\n");
}
