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

int	ft_puthex(unsigned long n, int count,char c)
{

	if ( n >= 0 && n <= 9)
		ft_putchar(n, count);
	else if (n > 9 && n < 16)
	{
		if (c == 'x')
			count = ft_putchar(n - 10 + 'a', count);
		else if(c == 'X')
			count = ft_putchar(n - 10 + 'A', count);
	}
	else
	{
		count = ft_puthex(n / 16, count, c);
		count = ft_puthex(n % 16, count, c);
	}
	return (count);
}
