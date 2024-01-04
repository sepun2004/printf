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
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int ft_putchar(char argument, int count)
{
    write(1, &argument, 1);
    return(count + 1);
}
char ft_putstr(char *argument, int count)
{
    
    int i = 0;
    int len = strlen(argument);
    while (i < len)
    {
        ft_putchar(argument[i], count);
        i++;
    }
    return(count);
}

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

int	ft_puthex(unsigned long n, int count,char c)
{

	if ( n >= 0 && n <= 9)
	{
		ft_putchar(n, count);
	}
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
    /*
    if (c == 'p')
        count = ft_putpointer(va_arg(argument, void *), count);
    */
    return(count);
}
//ft_print_all();


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


int main()
{
    int c = -123;

    ft_printf("%i", c);
    return 0;
}