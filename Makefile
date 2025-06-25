NAME	:= solong

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS	:=	\
		./check_file.c \
		./check_map.c \
		./copy_split.c \
		./create_delete.c \
		./floodfill.c \
		./handler.c \
		./main.c \
		./map.c \
		./move.c \
		./utils.c \

OBJS	:= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L/usr/lib -lmlx -lXext -lX11 -lm -lz -o $(NAME)

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@make clean -C libft
	@rm -f $(OBJS)

fclean	: clean
	@make fclean -C libft
	@rm -f $(NAME)

re		: fclean all

.PHONY: all clean fclean re