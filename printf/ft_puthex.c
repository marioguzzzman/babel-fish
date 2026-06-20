/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:02:43 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/20 17:45:06 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char x)
{
	unsigned int	base;
	char			*xlowermap;
	char			*Xuppermap;

	xlowermap = "0123456789abcdef";
	Xuppermap = "0123456789ABCDEF";
	base = 16;
	if (x == 'x')
		return (ft_putbase(n, base, xlowermap));
	else
		return (ft_putbase(n, base, Xuppermap));
}
