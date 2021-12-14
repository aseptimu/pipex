NAME = pipex

NAME_BONUS = ./bonus/pipex

LIB_NAME = libft/libft.a

LIB_SRC = ./libft

SRCS = main.c parent_process.c child_process.c \
		get_path.c

SRCS_BONUS = ./bonus/main_bonus.c ./bonus/child_process_bonus.c \
			./bonus/get_path_bonus.c ./bonus/ft_utils_bonus.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

CC = gcc

HEADER = pipex.h

HEADER_BONUS = ./bonus/pipex_bonus.h

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) -o $(NAME) 

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB_NAME) -o $(NAME)

$(LIB_NAME) : libft ;

libft :
	$(MAKE) -C $(LIB_SRC)

%.o : %.c $(if $(findstring bonus, $(MAKECMDGOALS)), $(HEADER_BONUS), $(HEADER))
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C $(LIB_SRC) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(MAKE) -C $(LIB_SRC) fclean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all libft clean fclean re