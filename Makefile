
SRCS = main.c ft_printf.c

all: ft_printf

test: ft_printf.txt printf.txt
	diff ft_printf.txt printf.txt

%.txt: %
	./$< > $@

ft_printf: $(SRCS)
	gcc $^ -D FT -o $@

printf: $(SRCS)
	gcc $^ -o $@

# clean:
# 	.o files

fclean:
	rm ft_printf printf ft_printf.txt printf.txt

re: fclean ft_printf printf
