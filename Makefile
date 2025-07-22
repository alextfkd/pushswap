NAME = push_swap
CC = cc
GCC = gcc -g

OBJDIR = ./objs
SRCDIR = ./srcs

SRCS = main.c validation.c error.c
#SRCS = $(addprefix  $(SRCDIR)/, $(SRCS))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes -Ift_printf/includes -Ilibft
LFLAGS = -Lft_printf -Llibft
LIBFLAGS = -lft -lftprintf

VPATH = $(SRCDIR)

all: $(OBJDIR) $(NAME) submodule

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS)  -o $@ $(LFLAGS) $(LIBFLAGS)

echo :
	echo ${SRCS}

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

submodule:
	echo 'submodule called'

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus objs libft ft_printf parser gnl camera_test aff3d_test parser_test minilibx