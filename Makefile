
SRCS = main.c ft_printf.c

test: ft_printf.txt printf.txt
	diff ft_printf.txt printf.txt

%.txt: %
	./$< > $@

ft_printf: $(SRCS)
	gcc $^ -D TEST -o $@

printf: $(SRCS)
	gcc $^ -o $@

clean:
	rm ft_printf printf
	rm ft_printf printf ft_printf.txt printf.txt
