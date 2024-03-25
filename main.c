#include <stdio.h>

int ft_printf(char *str);

#ifdef TEST
#define F(...) ft_printf(__VA_ARGS__);
#else
#define F(...) printf(__VA_ARGS__);

#endif

int main(void){
	F("abc\n");
	return (0);
}
