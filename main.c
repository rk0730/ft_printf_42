#include <stdio.h>
#include <stdlib.h>

int	ft_printf(char *str);

#ifdef FT
# define F(...) ft_printf(__VA_ARGS__);
#else
# define F(...) printf(__VA_ARGS__);

#endif

int	main(void)
{
	F("abc\n");
	//test
	return (0);
}
