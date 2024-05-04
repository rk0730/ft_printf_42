/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:18:29 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/04 21:03:08 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

// int	ft_putchar(char c)
// {
// 	// return (write(STDOUT_FILENO, &c, 1));
// 	return (printf("%c", c));
// }

int	ft_formats(char fmt, va_list *arg)
{
	if (fmt == '%')
		return (ft_convert_c('%'));
	else if (fmt == 'c')
		return (ft_convert_c((char)va_arg(*arg, int)));
	else if (fmt == 's')
		return (ft_convert_s(va_arg(*arg, char *)));
	// else if (fmt == 'p')
	// 	return (printf("%d", va_arg(*arg, int)));
	else if (fmt == 'd')
		return (ft_convert_d(va_arg(*arg, int)));
	else if (fmt == 'i')
		return (ft_convert_d(va_arg(*arg, int)));
	else if (fmt == 'u')
		return (ft_convert_u(va_arg(*arg, unsigned int)));
	// else if (fmt == 'x')
	// 	return (printf("%d", va_arg(*arg, int)));
	// else if (fmt == 'X')
	// 	return (printf("%d", va_arg(*arg, int)));
	write(STDOUT_FILENO, "error\n", 6);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ans;
	int		result;
	va_list	arg;

	i = 0;
	ans = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			result = ft_formats(format[i], &arg);
		}
		else
			result = ft_convert_c(format[i]);
		if (result == -1)
			return (-1);
		else
			ans += result;
		i++;
	}
	va_end(arg);
	return (ans);
}
