/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omrfrkzu <omrfrkzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:18:43 by omrfrkzu          #+#    #+#             */
/*   Updated: 2024/11/12 20:03:55 by omrfrkzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BASE10
#  define BASE10 "0123456789"
# endif

# ifndef BASE16LOWER
#  define BASE16LOWER "0123456789abcdef"
# endif

# ifndef BASE16UPPER
#  define BASE16UPPER "0123456789ABCDEF"
# endif

# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		format_selector(char format, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(uintptr_t n, char *base);
int		ft_putnbr(int nb);
int		ft_putnbr_base(int nbr, char *base);
int		ft_unsnd_putnbr_base(unsigned int nbr, char *base);
int		ft_strlen(const char *str);
#endif
