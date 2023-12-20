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
//#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_putchar(char argument, int count)
{
    write(1, &argument, 1);
    return(count + 1);
}
char ft_putstr(char *argument, int count)
{
    
    int i = 0;
    int len = ft_strlen(argument);
    while (i < len)
    {
        ft_putchar(argument[i], count);
        i++;
    }
    return(count);
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
    {
		write (1, "-2147483648", 11);
        return(count = 11);
    }
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
    else
    {
        ft_putchar(n + '0', count);
    }
}
/*
void	ft_puthexa(void *n)
{
	//if (n == -2147483648)
	//	ft_putstr("-2147483648");
	if (n <= 9)
	{
		ft_putchar("0x");
	}
	//if (n > 9)
	//{
	//	ft_putnbr(n / 10);
	//	ft_putnbr(n % 10);
	//}
	//if (n <= 9 && n != -2147483648)
	//	ft_putchar(n + '0');
}
//*/
int ft_select_type(va_list argument, char c, size_t count)
{
    if (c == 'c')
        count = ft_putchar(va_arg(argument, int), count);
    if (c == 's')
        count = ft_putstr(va_arg(argument, char *), count);
    if (c == 'i')
        count = ft_putnbr(va_arg(argument, int), count);
    return(count);
}
//ft_print_all();


int ft_printf(char const *str, ...)
{
    int i = 0;
    va_list argument;

    va_start(argument, str);
    while (*str != '\0')
    {
        if (*str == '%')
        {
            i++;
            i = ft_select_type(argument, str[i +1], i);
        }
        else
            i = ft_putchar(str[i], i);
        i++;
    }
    return (va_end(argument), i);
}


int main()
{
    int x = 2;

    ft_printf("%i", x);
    return 0;
}