/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:42:23 by sepun             #+#    #+#             */
/*   Updated: 2024/02/07 11:44:08 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char argument)
{
	int	count;

	count = 0;
	count += write(1, &argument, 1);
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *argument)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (argument == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (argument[i] != '\0')
	{
		count += ft_putchar(argument[i]);
		i++;
	}
	return (count);
}
