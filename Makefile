NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_strcmp.c\
	helpers.c\
	helpers2.c\
	helpers3.c\
	operations.c\
	push_atoi.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean : 
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
