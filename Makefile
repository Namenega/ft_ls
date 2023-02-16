SRCNAME		=	src/main.c \
				src/directory_utils/ft_printdir.c

SRCS 		= ${SRCNAME}

OBJS 		= ${SRCS:.c=.o}

FT_LS		= ft_ls

CC 			= gcc #-g -fsanitize=address
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -I./inc/libft -I./inc/ft_printf

CGREEN		= \033[38;2;0;153;0m
CRED		= \033[0;31m
CYELLOW		= \033[0;33m
CGREY		= \033[38;2;128;128;128m
CEND		= \033[0m


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${FT_LS}:	${OBJS}
		@echo
		@echo "$(CYELLOW)Libft compilation$(CEND)"
		@echo "$(CGREY)"
		make -C ./inc/libft
		@echo "$(CEND)"
		@echo "$(CGREEN)Compilation libft done !$(CEND)"
		@echo
		@echo "$(CYELLOW)Ft_printf compilation$(CEND)"
		@echo "$(CGREY)"
		make -C ./inc/ft_printf
		@echo
		@echo "$(CGREEN)Compilation ft_printf done !$(CEND)"
		@echo
		${CC} -o ${FT_LS} ${OBJS} -L./inc/libft -L./inc/ft_printf -lft -lftprintf
		@echo "$(CEND)"
		@echo "$(CGREEN)Compilation done !$(CEND)"
		@echo

all:		${FT_LS}

clean:
		@echo
		@echo "$(CYELLOW)Deleting .o files$(CEND)"
		@echo "$(CGREY)"
		make -C ./inc/libft clean
		@echo
		make -C ./inc/ft_printf clean
		@echo
		${RM} ${OBJS}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

fclean:		clean
		@echo "$(CYELLOW)Deleting .o files, libft.a, libftprintf.a and ft_ls$(CEND)"
		@echo "$(CGREY)"
		${RM} ${FT_LS} ./inc/libft/libft.a ./inc/ft_printf/libftprintf.a
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

re: 		fclean all

c: 			all clean

.PHONY: 	clean fclean all re
