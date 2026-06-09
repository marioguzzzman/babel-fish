/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:21 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/09 20:58:08 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	if (specifier == 'c')
		print_char(va_arg(ap, char))
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1),
		++format;
	}
	va_end(ap);
	return (count);
	int	main(void)
	{
		int	count;

		count = ft_printf("hello %s?\n", "john");
		ft_printf("the test: %d\n", count);
		return (0);
	}
