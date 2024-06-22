CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb
SRCS = get_next_line.c /
get_next_line-utils.c
OBJS = $(SRCS:.c=.o)
NAME = libgetnextline.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
