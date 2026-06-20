/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:49:22 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/20 15:22:57 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	long	ln;
	int		count;

	count = 0;
	ln = n;
	if (ln >= 10)
		count += ft_putunsigned(ln / 10);
	count += write(1, &"0123456789"[ln % 10], 1);
	return (count);
}
