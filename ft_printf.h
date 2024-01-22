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
#include <string.h>

//ft_print_pointer
int ft_print_hexamodificado(unsigned long long n);
int ft_putpointer(unsigned long long n);
//ft_printf_hex
int	ft_puthex(unsigned long n, char c);
//ft_printf_put_nbr
int	ft_putnbr(int n);
//ft_printf_str_char
int ft_putchar(char argument);
int ft_putstr(char *argument);
size_t	ft_strlen(const char *str);
//ft_printf
int	ft_printf(char const *str, ...);
int	ft_select_type(va_list argument, char c);
//ft_putnbr_unsinged
int	ft_putnbr_unsinged(unsigned int n);
#endif
