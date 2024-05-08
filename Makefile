CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address -g

SRCS = ft_printf.c \
	ft_convert_cs.c \
	ft_convert_d.c \
	ft_convert_u.c \
	ft_convert_p.c \

TEST_SRC = main.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

# leak: ft_printf
# 	leaks -q -atExit -- ./ft_printf

# sanitize: $(SRCS)
# 	$(CC) $(CFLAGS) $(SANITIZE) $^ -D FT -o $@

#printfデバッグの出力結果は.txtでは正しく見れない。./ft_printfを実行して確認する
#.txtはあくまでdiffをとる用にしか使えない

test: ft_printf.txt printf.txt
	diff ft_printf.txt printf.txt

%.txt: %
	./$< > $@

ft_printf: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) -I. $^ -D FT -o $@

printf: $(TEST_SRC)
	$(CC) $(CFLAGS) -I. $^ -o $@

clean:
	rm -rf sanitize.dSYM
	rm -f sanitize ft_printf.txt printf.txt
	rm -f $(OBJS)

fclean: clean
	rm -f printf ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re
