FLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g

SRCS = main.c ft_printf.c

all: ft_printf

leak: ft_printf
	leaks -q -atExit -- ./ft_printf

sanitize: $(SRCS)
	gcc $(FLAGS) $(SANITIZE) $^ -D FT -o $@

test: ft_printf.txt printf.txt
	diff ft_printf.txt printf.txt

%.txt: %
	./$< > $@

ft_printf: $(SRCS)
	gcc $(FLAGS) $^ -D FT -o $@

printf: $(SRCS)
	gcc $(FLAGS) $^ -o $@

# clean:
# 	rm -f .o files

fclean:
	rm -rf sanitize.dSYM
	rm -f ft_printf printf sanitize ft_printf.txt printf.txt

re: fclean ft_printf printf
