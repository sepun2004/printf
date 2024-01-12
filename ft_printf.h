/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:59:21 by sepun             #+#    #+#             */
/*   Updated: 2023/12/08 15:59:22 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <unistd.h>

//ft_print_pointer
int ft_print_hexamodificado(unsigned long n, int count);
int ft_putpointer(unsigned long n, int count);
//ft_printf_hex
int	ft_puthex(unsigned long n, int count,char c);
//ft_printf_put_nbr
int	ft_putnbr(int n, int count);
//ft_printf_str_char
int ft_putchar(char argument, int count)
#endif
