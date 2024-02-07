/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:57:58 by sepun             #+#    #+#             */
/*   Updated: 2024/02/07 11:30:06 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_select_type(va_list argument, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(argument, int));
	else if (c == 's')
		count += ft_putstr(va_arg(argument, char *));
	else if (c == 'i' || c == 'd')
		count += ft_putnbr(va_arg(argument, int));
	else if (c == 'u')
		count += ft_putnbr_unsinged(va_arg(argument, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(argument, unsigned int), c);
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'p')
		count += ft_putpointer(va_arg(argument, long int));
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_select_type(args, *str);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
