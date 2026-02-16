# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egonin <egonin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 20:24:40 by egonin            #+#    #+#              #
#    Updated: 2026/02/16 19:06:26 by egonin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  main_operations.c \
			  ps_long_sort.c \
			  ps_quick_sort.c \
			  ps_operations1.c \
			  ps_operations2.c \
			  ps_operations3.c \
			  utils1.c \
			  utils2.c \
			  utils3.c \

	  
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCS		= -I. -I$(LIBFT_DIR)

NAME		= push_swap

all:		$(NAME)	

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o:		%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: clean fclean all re
