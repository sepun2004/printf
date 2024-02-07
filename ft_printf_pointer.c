/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:42:23 by sepun             #+#    #+#             */
/*   Updated: 2024/02/07 11:41:12 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hexamodificado(unsigned long long n)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putchar(n + '0');
	else if (n > 9 && n < 16)
		count += ft_putchar(n - 10 + 'a');
	else
	{
		count += ft_print_hexamodificado(n / 16);
		count += ft_print_hexamodificado(n % 16);
	}
	return (count);
}

int	ft_putpointer(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_print_hexamodificado(n);
	return (count);
}
