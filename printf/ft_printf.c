/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:21 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/19 19:37:36 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(int d, int base)
{
	(void) d;
	(void) base;
	write(1, "u", 1);
	return (1);
}

int	ft_selector(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar((char) va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'x')
		count += ft_putunsigned(va_arg(ap, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_selector(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
int	count;

count = ft_printf("hello %s\n", "dull boy");
ft_printf("str test: %s\n", "dull boy");
ft_printf("the test: %d\n", count);
ft_printf("char test: %c\n", 'd');
printf("hello %s\n", "dull boy");
return (0);
}
*/
