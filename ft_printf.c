/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:57:58 by sepun             #+#    #+#             */
/*   Updated: 2023/12/08 15:58:01 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_select_type(va_list argument, char c, size_t count)
{
    if (c == 'c')
        count = ft_putchar(va_arg(argument, int), count);
    if (c == 's')
        count = ft_putstr(va_arg(argument, char *), count);
    if (c == 'i'  || c == 'd')
        count = ft_putnbr(va_arg(argument, int), count);
	if (c == 'u')
		count = ft_putnbr(va_arg(argument, unsigned int), count);
	if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(argument, unsigned int), count, c);
	if (c == '%')
        count = ft_putchar('%', count);
    if (c == 'p')
        count = ft_putpointer(va_arg(argument, void *), count);
    
    return(count);
}


int	ft_printf(char const *str, ...)
{
	int		bytes;
	va_list	args;

	bytes = 0;
	va_start(args, str);
	while (*str != '\0')
	{
	    if (*str == '%')
		{
			str++;
			bytes = ft_select_type(args, *str, bytes);
		}
		else
			bytes = ft_putchar(*str, bytes);
		str++;
	}
	return (va_end(args), bytes);
}