#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwalee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/04 20:20:49 by hwalee            #+#    #+#              #
#    Updated: 2020/10/13 22:16:24 by hwalee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strchr.c ft_strrchr.c \
	  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_calloc.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_substr.c \
	  ft_strjoin.c ft_split.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_hax.c ft_u_itoa.c \
	  ft_strnjoin.c ft_oct.c
B_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o : %.c libft.h
	$(CC) $(CLFAGS) -c $< -o $@

bonus : $(B_OBJS)
	ar cr $(NAME)  $(B_OBJS)

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
