NAME = libftprintf.a
SOURCES = ft_printf.c \
			ft_putcharint.c \
			ft_putstrint.c \
			ft_voidhex.c \
			ft_putnbrint.c \
			ft_putnbrun.c \
			ft_lowerhex.c \
			ft_upperhex.c 

OBJECTS = $(SOURCES:.c=.o)                                                 

CC = cc                                                                      
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf                                                                     

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	
clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re