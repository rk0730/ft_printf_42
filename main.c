/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:30:29 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/04 21:13:41 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

#ifdef FT
# define PRINTF ft_printf
#define F(...) ft_printf("\n ∟ res %d\n\n", ft_printf(__VA_ARGS__));
#else
#define F(...) printf("\n ∟ res %d\n\n", printf(__VA_ARGS__));

#endif

int	main(void)
{
	// F("[%c2 Tokyo]", '4');
	// F("[42 %s]", "Tokyo");
	// F("[%p Tokyo]", (void *)10);
	// F("[%d Tokyo]", 42);
	// int	i = -2147483648;
	// F("%d", i);
	// F("%d", 2147483648);
	// F("%d", 2147483647);
	// F("%d", 0);
	// F("%d", 12345);
	// F("%d", -1);
	// F("[%i Tokyo]", 42);
	// F("[%u Tokyo]", 42);
	// F("[%x Tokyo]", 42);
	// F("[%X Tokyo]", 42);
	// F("[42%% Tokyo]");
	F("%u", 0);
	F("%u", 10);
	F("%u", 9876543);
	F("%u", -1);

	F("%p", "abc");
	F("%c %c", '1', '2');
	return (0);
}
