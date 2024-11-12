/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omrfrkzu <omrfrkzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:12:52 by omrfrkzu          #+#    #+#             */
/*   Updated: 2024/11/12 20:00:49 by omrfrkzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		tmp;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			tmp = format_selector(format[i + 1], args);
			if (tmp == -1)
				return (-1);
			count += (tmp - 1);
			i++;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		count++;
		i++;
	}
	va_end(args);
	return (count);
}

int	format_selector(char format, va_list args)
{
	uintptr_t	ptr;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		ptr = (uintptr_t)va_arg(args, void *);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
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
	return (0);
}
