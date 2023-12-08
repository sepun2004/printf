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
//#include "ft_printf.h"

char ft_putchar(char argument)
{
    write(1, &argument, 1);
}
char *ft_putstr(char *argument)
{
    
    int i = 0;
    int len = strlen(argument);

    while (i < len)
    {
        write(1, &argument[i], 1);
        i++;
    }
    
}


char ft_select_type(va_list argument, char c)
{
    //int i = 0;

    if (c == 'c')
        ft_putchar(va_arg(argument, char));
    if (c == 's')
        ft_putstr(va_arg(argument, char *));
    if (c == 'p')
        ft_puthexadecimal(va_arg(argument, char *));
}
//ft_print_all();


int ft_printf(char const *str, ...)
{
    int i = 0;
    va_list argument;

    va_start(argument, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            ft_select_type(argument, str[i +1]);
            i++;
        }
        else
        //ft_print_all(str);
        //i++;
        return(0);
    }
    va_end(argument);
}

int main()
{
    //char x = 'c';
    //char *str = "hola";
    void *str = "hola";

    //ft_printf("%c\n", x);
    //ft_printf("%s\n", str);
}