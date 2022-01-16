# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 14:46:27 by sunbchoi          #+#    #+#              #
#    Updated: 2021/11/30 18:48:35 by sunbchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS = main.c\
		error_manager.c\
		init.c\
		utils.c\
		launcher.c\
		
OBJS = $(SRCS:.c=.o)
NAME = philo
RM = rm -f

all: $(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(CFLAG) -o $@ $(OBJS)

%o:			%.c
			$(CC) $(CFLAGS)  -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:
			make clean
			$(RM) $(NAME)

re:
			make fclean all

.PHONY:		all clean fclean re