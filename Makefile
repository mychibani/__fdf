# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 10:09:52 by ychibani          #+#    #+#              #
#    Updated: 2022/07/07 17:02:28 by ychibani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES		=	srcs/fdf/main.c					\
					srcs/parsing/parsing.c			\
					srcs/events/events.c			\
					srcs/init/init.c 				\
					srcs/init/init_map_data.c		\
					srcs/init/init_mlx.c 			\
					srcs/init/init_points.c 		\
					srcs/print_debug/print_debug.c 	\
					srcs/clean/clean_quit.c			\
					srcs/utils/mlx_utils.c			\


HEADER_FILES		=	libft.h						\
						fdf_structs.h 				\
						fdf_fonctions.h				\
						fdf_defines.h				\

NAME			=	fdf

OBJS_FILES 		= 	${SRCS_FILES:.c=.o}

DEPS_FILES		=	${SRCS_FILES:.c=.d}

INCS			=	-I ./includes -I libft/includes -I mlx

LIBFT			=	libft/libft.a

CC			=	gcc 

CFLAGS			=  	-Wall -Werror -Wextra #-fsanitize=address -g3

MLX			=	-L ./mlx/ -lmlx -lXext -lX11 -lm -O3
	
RM			=	rm -rf


_END=$'\e[0m
_BOLD=$'\e[1m
_UNDER=$'\e[4m
_REV=$'\e[7m
_GREY=$'\e[30m
_RED=$'\e[0;31m
_GREEN=$'\e[32m
_YELLOW=$'\e[33m
_BLUE=$'\e[34m
_PURPLE=$'\e[35m
_CYAN=$'\e[36m
_WHITE=$'\e[37m

_IGREY=$'\e[40m
_IRED=$'\e[41m
_IGREEN=$'\e[42m
_IYELLOW=$'\e[43m
_IBLUE=$'\e[44m
_IPURPLE=$'\e[45m
_ICYAN=$'\e[46m
_IWHITE=$'\e[47m


all:			${NAME}

.c.o:
				@echo "Compiling ${_YELLOW}${_BOLD}$<${_END}..."
				@${CC} ${CFLAGS} -g ${INCS} -MMD -c $< -o $@ ${INCS}

${NAME}:		${OBJS_FILES}
				@echo "Compiling ${_GREEN}${_BOLD}libft and mlx${_END}..."
				@${MAKE} -C libft >/dev/null
				@${MAKE} -C mlx >/dev/null
				@echo "Compiling ${_CYAN}${_BOLD}fdf files${_END}..."
				@${CC} ${CFLAGS} ${INCS} ${OBJS_FILES} -o ${NAME} ${MLX} ${LIBFT}

clean:
				@echo "Deleting ${_RED}${_BOLD}binary files and mlx${_END}..."
				@${RM} ${OBJS_FILES} ${DEPS_FILES}
				@echo "Deleting ${_RED}${_BOLD}libft binary files${_END}..."
				@${MAKE} -C libft fclean >/dev/null
				@${MAKE} -C mlx clean >/dev/null

fclean:			clean
				@echo "Deleting ${_RED}${_BOLD}fdf${_END}..."
				@${RM} ${OBJS_FILES}

re:				fclean all

git :
		git add .
		git commit -m "$m"
		git push -u origin master 

-include ${DEPS_FILES}

.PHONY:			all clean fclean re bonus
