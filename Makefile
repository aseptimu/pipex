NAME = pipex

LIB_NAME = libft/libft.a

LIB_SRC = ./libft

SRCS = main.c parent_process.c child_process.c \
		get_path.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIB_NAME)
	gcc $(OBJS) $(LIB_NAME) -o $(NAME) 

$(LIB_NAME) : libft ;

libft :
	$(MAKE) -C $(LIB_SRC)

%.o : %.c
	gcc -c $< -o $@

clean :
	$(MAKE) -C $(LIB_SRC) clean
	rm -f $(OBJS)

fclean :
	$(MAKE) -C $(LIB_SRC) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all libft clean fclean re