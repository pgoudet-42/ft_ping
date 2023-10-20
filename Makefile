SRCS = ./srcs/checksums.c ./srcs/display_results.c ./srcs/ft_ping.c ./srcs/received_request.c ./srcs/send_request.c ./srcs/utils.c
INCLUDES = ./includes/ft_ping.h ./libft/libft.h
PATH_LIB = /home/pgoudet/Documents/ft_ping/libft
LIB = ft
NAME = ft_ping
FLAGS = -Wall -Wextra -Werror


OBJS = ${SRCS:.c=.o}

%.o : %.c ${INCLUDES}
	gcc ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	$(MAKE) -C ./libft
	gcc $(FLAGS) $(SRCS) -L${PATH_LIB} -l${LIB} -o ${NAME} -lm

all: $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean :	clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all fclean clean re
