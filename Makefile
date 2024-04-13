CC = cc
FLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g

SRCS = main.c ft_printf.c

all: ft_printf

leak: ft_printf
	leaks -q -atExit -- ./ft_printf

sanitize: $(SRCS)
	$(CC) $(FLAGS) $(SANITIZE) $^ -D FT -o $@

test: ft_printf.txt printf.txt
	diff ft_printf.txt printf.txt

%.txt: %
	./$< > $@

ft_printf: $(SRCS)
	$(CC) $(FLAGS) $^ -D FT -o $@

printf: $(SRCS)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf sanitize.dSYM
	rm -f sanitize ft_printf.txt printf.txt
#	rm -f .o files

fclean: clean
	rm -f ft_printf printf

re: fclean ft_printf printf

.PHONY: all leak sanitize test ft_printf printf
