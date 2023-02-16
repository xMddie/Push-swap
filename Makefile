# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 08:46:51 by mnau              #+#    #+#              #
#    Updated: 2023/02/02 20:53:36 by mnau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			=	args_parser.c \
					args_checker.c \
					push_swap.c \
					other_utils.c \
					sort_utils.c \
					s_moves.c \
					p_moves.c \
					r_moves.c \
					tinyalgo.c \
					midalgo.c \
					bigalgo_utils.c \
					bigalgo.c \
					free_stacks.c \
					actions_printer.c
					
OBJS			= $(SRCS:.c=.o)

RM				= rm -f

NAME			= push_swap

LIBFT			= ./Libft

# COLORS #

BLACK	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN 	= \033[0;36m
WHITE	= \033[0;37m
CLEAR	= \r\033[K

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
				@printf "$(CLEAR)$(BCYAN)⏳ Compiling... $(PURPLE)<$<> 🌸"
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@printf "$(CLEAR)$(BCYAN)⌛️ Compiling... $(GREEN)\"Libft\"\e[0m 🌸\n"
				@make -C $(LIBFT)
				@printf "$(BCYAN)⌛️ Compiling... $(GREEN)\"$(NAME)\"\e[0m 🌸\n"
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./Libft/libft.a

clean:
				@make clean -C $(LIBFT)
				@printf "$(BRED)Cleaning project... ✅\n\e[0m"
				@$(RM) $(OBJS)

fclean:
				@make fclean -C $(LIBFT)
				@printf "$(BRED)Force cleaning Push swap project... ✅\n\e[0m"
				@$(RM) $(OBJS) $(NAME) $(TEST)

re:				fclean all

.PHONY:			all clean fclean re