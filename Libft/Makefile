# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 08:46:51 by mnau              #+#    #+#              #
#    Updated: 2023/02/01 12:30:49 by mnau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
					
OBJS			= $(SRCS:.c=.o)

RM				= rm -f

NAME			= libft.a

#TEST			= ft-libft-test

# COLORS #

BLACK	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN 	= \033[0;36m
WHITE	= \033[0;37m

# BOLD COLORS #

BBLACK	= \033[1;30m
BRED 	= \033[1;31m
BGREEN 	= \033[1;32m
BYELLOW = \033[1;33m
BBLUE	= \033[1;34m
BPURPLE	= \033[1;35m
BCYAN 	= \033[1;36m
BWHITE	= \033[1;37m



.c.o:			$(SRCS)
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

#$(TEST):		$(OBJS)
#				@printf "$(CYAN)Compiling... \"$(TEST)\"... \n\e[0m"
#				@$(CC) -o $(TEST) $(OBJS)
#				@printf "\e[1;36mExecuting \"$(TEST)\"... \n\e[0m"
#				@./$(TEST)

clean:
				@printf "$(BRED)Cleaning Libft project... ✅\n\e[0m"
				@$(RM) $(OBJS)

fclean:
				@printf "$(BRED)Force cleaning Libft project... ✅\n\e[0m"
				@$(RM) $(OBJS) $(NAME) $(TEST)

re:				fclean all

.PHONY:			all clean fclean re