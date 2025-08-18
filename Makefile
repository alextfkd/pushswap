NAME = push_swap
CC = cc -g
GCC = gcc -g

OBJDIR = ./objs
SRCDIR = ./srcs

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

SRCS = main.c

CDLST = cdlst_create.c cdlst_delete.c cdlst_findnode.c cdlst_insert.c cdlst_utils.c cdlst_rotate.c
CDLST_OBJS = $(addprefix $(OBJDIR)/, $(CDLST:.c=.o))

WRAP = wrap_p.c wrap_s.c wrap_r.c wrap_rr.c
WRAP_OBJS = $(addprefix $(OBJDIR)/, $(WRAP:.c=.o))

STACKOPS = stacks_create.c stacks_push.c stacks_utils.c stacks_cmp.c stacks_delete.c stacks_from_arr.c
STACKOPS_OBJS = $(addprefix $(OBJDIR)/, $(STACKOPS:.c=.o))

UTILS = error.c validation.c
UTILS_OBJS = $(addprefix $(OBJDIR)/, $(UTILS:.c=.o))

SORT = check_sort_status.c top3_sort.c top3_sort_ops.c sort_ops.c count_sorted.c print_sort_ops.c reverse_sort_ops.c sort_utils.c naive_radix_sort.c
SORT_OBJS = $(addprefix $(OBJDIR)/, $(SORT:.c=.o))

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes -Ift_printf/includes -Ilibft
LFLAGS = -Lft_printf -Llibft
LIBFLAGS = -lft -lftprintf

VPATH = $(SRCDIR):$(SRCDIR)/ft_cdlst:$(SRCDIR)/ps_wrap:$(SRCDIR)/stacks:$(SRCDIR)/ps_utils:$(SRCDIR)/sort

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS) $(CDLST_OBJS) $(WRAP_OBJS) $(STACKOPS_OBJS) $(UTILS_OBJS) $(SORT_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS)  $(CDLST_OBJS) $(WRAP_OBJS) $(STACKOPS_OBJS) $(UTILS_OBJS) $(SORT_OBJS) -o $@ $(LFLAGS) $(LIBFLAGS)

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