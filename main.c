/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:30:29 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/14 00:30:31 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);

#ifdef FT
# define PRINTF ft_printf
#else
# define PRINTF printf

#endif

int	main(void)
{
	PRINTF("a%%b12%d%d\n", 345, 678);
	return (0);
}
