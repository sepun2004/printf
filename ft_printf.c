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

void    ft_putchar(char argument)
{
    write(1, &argument, 1);
}
void    ft_putstr(char *argument)
{
    
    int i = 0;
    int len = strlen(argument);
    while (i < len)
    {
        ft_putchar(argument[i]);
        i++;
    }
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9 && n != -2147483648)
		ft_putchar(n + '0');
}
//ft_puthexadecimals
void


char ft_select_type(va_list argument, char c)
{
    //int i = 0;

    if (c == 'c')
        ft_putchar(va_arg(argument, char));
    if (c == 's')
        ft_putstr(va_arg(argument, char *));
    if (c == 'i')
        ft_putnbr(va_arg(argument, int));
    if (c == 'u')
        ft_putnbr(va_arg(argument, int));
}
//ft_print_all();


int ft_printf(char const *str, ...)
{
    int i = 0;
    va_list argument;

    va_start(argument, str);
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            ft_select_type(argument, str[i +1]);
            i++;
        }
        else
        ft_putchar(str[i]);
        i++;
    }
    va_end(argument);
    return(0);
}


int main()
{
    /*char x = 'c';
    char *str = "hola";
    int n = 2000000;*/

    //ft_printf("%i\n", x);
    /*ft_printf(x);
    ft_printf(str);
    ft_printf(n);*/
    ft_printf("hola");
}