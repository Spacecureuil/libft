# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmaury <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 10:44:55 by pmaury            #+#    #+#              #
#    Updated: 2021/03/30 10:47:09 by pmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memcpy.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcat.c ft_strlen.c \
	ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_substr.c ft_strtrim.c ft_split.c \
	ft_tolower.c ft_toupper.c \

BONUS_FUNCT = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

BNS = ${BONUS_FUNCT:.c=.o}

OBJS = ${SRCS:.c=.o}

CC		= gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}

bonus: ${OBJS} ${BNS}
		ar rc ${NAME} ${OBJS} ${BNS}

all:	${NAME}

.PHONY: clean bonus fclean re all

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all