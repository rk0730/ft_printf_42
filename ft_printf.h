/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:08:56 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/08 11:38:48 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_formats(char fmt, va_list *arg);
int	ft_convert_c(char c);
int	ft_convert_s(char *str);
int	ft_convert_d(int num);
int	ft_convert_i(int num);
int	ft_convert_u(unsigned int num);
int	ft_convert_p(void *address);

#endif
