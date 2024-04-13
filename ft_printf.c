/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:18:29 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/14 00:28:59 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	// return (write(STDOUT_FILENO, &c, 1));
	return (printf("%c", c));
}

int	ft_formats(char fmt, va_list *arg)
{
	//変換指定子ごとに分岐する場所　各戻り値はそれぞれ対応する関数が入る
	if (fmt == '%')
		return (ft_putchar('%'));
	else if (fmt == 'd')
		return (printf("%d", va_arg(*arg, int)));
	else if (fmt == 'c')
		return (printf("%c", (char)va_arg(*arg, int)));
	printf("error\n");
	return (0);
}


int	ft_printf(const char *format, ...)
{
	int		i;
	int		ans;
	va_list	arg;

	i = 0;
	ans = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ans += ft_formats(format[i], &arg);
		}
		else
			ans += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (ans);
}
