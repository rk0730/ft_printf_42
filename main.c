/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1652952399 <1652952399@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:30:29 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/08 18:47:34 by 1652952399       ###   ########.fr       */
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
	char	*str = NULL;
	F("%s", str);

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

	// %xX テスト
	F("%x", 0);
	F("%x", 12345);
	F("%x", UINT_MAX);
	F("%x", INT_MAX);
	F("%X", 0);
	F("%X", 12345);
	F("%X", UINT_MAX);
	F("%X", INT_MAX);

	return 0;
}
