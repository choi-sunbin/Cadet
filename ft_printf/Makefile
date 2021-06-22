# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwalee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 13:11:18 by hwalee            #+#    #+#              #
#    Updated: 2021/06/12 13:38:55 by sunbchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
NAME = libftprintf.a
LIBFTDIR = libft
LIBFT = libft.a
CFALGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_printf_d.c ft_utils.c ft_size_d.c \
		ft_tag.c ft_printf_c.c ft_printf_s.c ft_printf_u.c\
		ft_printf_x.c ft_printf_p.c ft_printf_per.c ft_printf_oct.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR)/
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	ar cr $@ $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBFTDIR)/
	rm -f $(OBJS)
fclean : clean
	$(MAKE) fclean -C $(LIBFTDIR)/
	rm -f $(NAME)

re : fclean clean all

