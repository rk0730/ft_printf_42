/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:30:29 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/08 13:01:35 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

#ifdef FT
# define PRINTF ft_printf
#define F(...) ft_printf("\n ∟ res %d\n\n", ft_printf(__VA_ARGS__));
#else
#define F(...) printf("\n ∟ res %d\n\n", printf(__VA_ARGS__));

#endif

int main(void)
{
	// %% テスト
	F("%%%%");

	// %c テスト
	F("%c", 'A');
	F("%c", 'B');
	F("%c", 'C');

	// %s テスト
	F("%s", "Tokyo");
	F("%s", "Osaka");
	F("%s", "Kyoto");

	// %p テスト
	F("%p", (void *)12345);
	F("%p", (void *)0);

	// %d, %i テスト
	F("%d", 0);
	F("%d", 12345);
	F("%d", -1234);
	F("%d", 987654);
	F("%d", -987654);
	F("%d", INT_MAX);
	F("%d", INT_MIN);

	// %u テスト
	F("%u", 0);
	F("%u", 12345);
	F("%u", UINT_MAX);

	return 0;
}
