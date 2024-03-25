
test: ft_printf printf
	./ft_printf > ft_printf.txt
	./printf > printf.txt
	diff ft_printf.txt printf.txt

ft_printf: main.c ft_printf.c
	gcc main.c ft_printf.c -D TEST -o ft_printf

printf: main.c
	gcc main.c -o printf

clean:
	rm ft_printf printf ft_printf.txt printf.txt
