/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1652952399 <1652952399@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:36:15 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/08 18:22:05 by 1652952399       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	ft_convert_p_h(unsigned long long num, int res)
{
	int	tmp;

	if (res == -1)
		return (-1);
	if (num >= 16)
	{
		tmp = ft_convert_p_h(num / 16, res);
		if (tmp == -1)
			return (-1);
		else
			res += tmp;
	}
	tmp = ft_convert_c("0123456789abcdef"[num % 16]);
	if (tmp == -1)
		return (-1);
	else
		return (res + tmp);
}

int	ft_convert_p(void *address)
{
	unsigned long long	num;
	int					res;

	num = (unsigned long long)address;
	res = 0;
	if (write(STDOUT_FILENO, "0x", 2) == -1)
		return (-1);
	else
		res += 2;
	res += ft_convert_p_h(num, 0);
	return (res);
}
