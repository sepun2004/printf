/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:42:23 by sepun             #+#    #+#             */
/*   Updated: 2023/12/08 16:42:25 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char c)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putnbr(n);
	else if (n >= 10 && n < 16)
	{
		if (c == 'x')
			count += ft_putchar(n - 10 + 'a');
		else if (c == 'X')
			count += ft_putchar(n - 10 + 'A');
	}
	else
	{
		count += ft_puthex(n / 16, c);
		count += ft_puthex(n % 16, c);
	}
	return (count);
}
