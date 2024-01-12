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

int ft_print_hexamodificado(unsigned long n, int count)
{
	if ( n >= 0 && n <= 9)
		ft_putchar(n, count);
	else if (n > 9 && n < 16)
	{
		count = ft_putchar(n - 10 + 'a', count);
	}
	else
	{
		count = ft_putpointer(n / 16, count);
		count = ft_putpointer(n % 16, count);
	}
	return (count);
}

int ft_putpointer(unsigned long n, int count)
{
	count = ft_putstr("0x");
	count = ft_print_hexamodificado(n, count);
}
