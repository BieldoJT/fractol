# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 22:09:01 by gda-conc          #+#    #+#              #
#    Updated: 2024/11/18 22:09:01 by gda-conc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a



CC = cc

FLAGS = -Wall -Werror -Wextra


SRCS 		= ft_isalpha.c 			\
			ft_isdigit.c 			\
			ft_isalnum.c 			\
			ft_isascii.c 			\
			ft_isprint.c 			\
			ft_strlen.c 			\
			ft_memset.c 			\
			ft_bzero.c 				\
			ft_memcpy.c 			\
			ft_memmove.c 			\
			ft_strlcpy.c 			\
			ft_strlcat.c 			\
			ft_toupper.c 			\
			ft_tolower.c 			\
			ft_strchr.c 			\
			ft_strrchr.c 			\
			ft_strncmp.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strnstr.c			\
			ft_atoi.c 				\
			ft_strdup.c 			\
			ft_calloc.c 			\
			ft_strnstr.c 			\
			ft_itoa.c 				\
			ft_substr.c	 			\
			ft_split.c 				\
			ft_strjoin.c 			\
			ft_strtrim.c			\
			ft_itoa.c 				\
			ft_strmapi.c 			\
			ft_striteri.c 			\
			ft_putchar_fd.c 		\
			ft_putstr_fd.c 			\
			ft_putendl_fd.c 		\
			ft_putnbr_fd.c			\
			ft_count_occurrences.c	\
			get_next_line.c			\
			ft_printf.c				\
			ft_argument_c.c			\
			ft_arguments_d_i.c		\
			ft_argument_p.c			\
			ft_argument_percent.c	\
			ft_argument_s.c			\
			ft_argument_u.c			\
			ft_arguments_x.c		\
			ft_print_reversed_str.c	\
			ft_free_ptr.c			\
			ft_hex_length.c			\
			ft_decimal_length.c		\
			ft_decimal_converter_to_hex.c

BONUS_SRCS  	= ft_lstnew.c	\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all:	${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus: ${NAME} ${BONUS_OBJS}
	ar -rcs ${NAME} ${BONUS_OBJS}



clean:
	rm -rf ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
