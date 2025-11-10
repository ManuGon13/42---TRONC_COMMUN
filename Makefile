# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egonin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 20:24:40 by egonin            #+#    #+#              #
#    Updated: 2025/11/10 20:44:51 by egonin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= isalpha.c \
		  isdigit.c \
		  isalnum.c \
		  isascii.c \
		  isprint.c \
		  strlen.c \
		  memset.c \
	 	  bzero.c \
		  memcpy.c \
		  memmove.c \
		  strlcpy.c \
		  strlcat.c \
		  toupper.c \
		  tolower.c \
		  strchr.c \
		  strrchr.c \
		  strncmp.c \
		  memchr.c \
		  memcmp.c \
		  strnstr.c \
		  atoi.c \
		  calloc.c \
		  strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
	  
OBJS		= $(patsubst %.c, %.o, $(SRCS))

NAME		= libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:		%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean all
