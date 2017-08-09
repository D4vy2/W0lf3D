NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_itoa.c
SRC += ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c
SRC += ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c
SRC += ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c
SRC += ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c
SRC += ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strsplit.c
SRC += ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
SRC += ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c
SRC += ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC += ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c
SRC += ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c
SRC += ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strsub.c
SRC += ft_strtrim.c ft_tolower.c ft_toupper.c ft_isupper.c
SRC += ft_islower.c ft_isspace.c ft_lstadd.c ft_lstdel.c
SRC += ft_lstdelone.c ft_lstiter.c ft_lstnew.c ft_lstmap.c


DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo
	@echo "make -> $(NAME) created"
	@echo

clean:
	@$(DEL) $(OBJ)
	@echo
	@echo "clean -> .o deleted"
	@echo

fclean: clean
	@$(DEL) $(NAME)
	@echo
	@echo "fclean -> ... and $(NAME) deleted"
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded"
	@echo

.PHONY: all clean fclean re
