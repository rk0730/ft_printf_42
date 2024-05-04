/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:54:35 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/04 21:08:11 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_c(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_convert_s(char *str)
{
	int	tmp;
	int	res;

	tmp = 0;
	res = 0;
	while (tmp != -1 && *str)
	{
		tmp = write(STDOUT_FILENO, str, 1);
		if (tmp == -1)
			return (-1);
		else
			res += tmp;
		str++;
	}
	return (res);
}
