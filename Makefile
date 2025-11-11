NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -Iincludes
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRCS			=	ft_printf.c ft_printchar.c ft_printstr.c ft_printnum.c ft_printunsigned.c ft_printhex.c ft_printptr.c

OBJS			=	$(SRCS:.c=.o)

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

%.o:				%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_DIR) all

clean:
					make -C $(LIBFT_DIR) fclean
					$(RM) $(OBJS)

fclean:				clean
					make -C $(LIBFT_DIR) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
