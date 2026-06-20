/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:57:16 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/20 17:28:15 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned int n, unsigned int base, char *map)
{
	int			count;
	long int	ln;

	count = 0;
	ln = n;
	if (ln >= base)
		count += ft_putbase(ln / base, base, map);
	count += write(1, &map[ln % base], 1);
	return (count);
}
