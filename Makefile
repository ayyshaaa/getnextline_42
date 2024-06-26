CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb -Igetnextline
SRCS = get_next_line.c \
get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = libgetnextline.a
AR = ar rcs

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
