/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 22:01:18 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/17 18:14:17 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
		len++;
	return (len);
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	main(void)
{
	int	count;

	write(1, "Testing ft_putstr:\n", 19);
	count = ft_putstr("Hello, World!");
	write(1, "\n", 1);
	ft_printf("Characters written: %d\n", count);
	count = ft_putstr("42");
	write(1, "\n", 1);
	ft_printf("Characters written: %d\n", count);
	count = ft_putstr("");
	write(1, "\n", 1);
	ft_printf("Characters written for empty string: %d\n", count);
	return (0);
}
