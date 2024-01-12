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
