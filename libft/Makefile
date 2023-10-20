# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 12:43:48 by pgoudet           #+#    #+#              #
#    Updated: 2021/04/11 12:43:50 by pgoudet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c      ft_memcmp.c       ft_putstr_fd.c  ft_strlcat.c    ft_strnstr.c    ft_toupper.c \
ft_atoi.c       ft_isascii.c    ft_memccpy.c     ft_memset.c     ft_split.c      ft_strlcpy.c    ft_strrchr.c  \
ft_bzero.c      ft_isdigit.c    ft_memcpy.c      ft_putchar_fd.c ft_strchr.c     ft_strlen.c     ft_strtrim.c  \
ft_calloc.c     ft_isprint.c    ft_memchr.c      ft_putendl_fd.c ft_strdup.c     ft_strmapi.c    ft_substr.c   \
ft_isalnum.c    ft_itoa.c       ft_memmove.c     ft_putnbr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c  \
ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_strcmp.c \
ft_lstclear.c ft_lstclear.c ft_lstiter.c

OBJS = ${SRCS:.c=.o}

OBJS2 = ${BONUS_OBJ:.c=.o}

NAME = libft.a

CC = gcc

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

bonus: ${OBJS2}
	ar rc ${NAME} ${OBJS2}
	ranlib ${NAME}

clean:
	${RM} ${OBJS} ${OBJS2}

fclean: clean
	${RM} ${NAME}

re:	fclean all
