SRCS = $(wildcard check_error/*.c free_leaks/*.c libf_t/*.c push_swapp/*.c sorting_tools/*.c \
		stack_managment/*.c) main.c
       
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
DPRINTF = ft_printf
PATH_PRINTF = ./ft_printf/libftprintf.a

all: ${NAME}

${NAME}: ${OBJS} swap_push.h
	make all -C ${DPRINTF}
	${CC} ${CFLAGS} ${PATH_PRINTF} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C ${DPRINTF}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${DPRINTF}
	${RM} ${NAME}

re: fclean all

.PHONY: clean
