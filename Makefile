NAME = push_swap
CC = cc -g
GCC = gcc -g

OBJDIR = ./objs
SRCDIR = ./srcs

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

SRCS = main.c validation.c error.c
SRCS += cdlst_create.c cdlst_delete.c cdlst_findnode.c cdlst_insert.c cdlst_utils.c cdlst_push_rotate.c
#SRCS = $(addprefix  $(SRCDIR)/, $(SRCS))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes -Ift_printf/includes -Ilibft
LFLAGS = -Lft_printf -Llibft
LIBFLAGS = -lft -lftprintf

VPATH = $(SRCDIR)

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS)  -o $@ $(LFLAGS) $(LIBFLAGS)

echo :
	echo ${SRCS}

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	make --directory ./libft/

libft_clean:
	make --directory ./libft/ clean

$(FT_PRINTF):
	make --directory ./ft_printf/

ft_printf_clean:
	make --directory ./ft_printf/ clean

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: libft_clean ft_printf_clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) ./libft/libft.a ./ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re bonus objs libft ft_printf parser gnl camera_test aff3d_test parser_test minilibx