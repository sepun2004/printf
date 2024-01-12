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

int	ft_putnbr(int n, int count)
{
	if (n < 0)
	{
	    write(1, "-", 1);
		n *= -1;
		count++;
	}
	if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putchar(n % 10 + '0', count);
	}
	else
		count = ft_putchar(n + '0', count);
	return (count);
}