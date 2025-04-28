# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:52:46 by tde-los-          #+#    #+#              #
#    Updated: 2023/03/01 13:48:15 by tde-los-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT_DIR = ../libft

PRINTF_SRCS = ft_printf.c ft_printstr.c ft_putnbr.c

LIBFT_SRCS = $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_bzero.c

SRCS = $(PRINTF_SRCS) $(LIBFT_SRCS)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
