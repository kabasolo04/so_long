NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_isascii.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_strncmp.c \
	ft_isalnum.c \
	ft_strnstr.c \
	ft_isalpha.c \
	ft_strrchr.c \
	ft_isdigit.c \
	ft_tolower.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	 \
	ft_calloc.c \
	ft_strdup.c \
	 \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	\
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	\
	ft_printf.c \
	get_next_line.c \
	ft_ismayus.c \
	ft_islowcase.c \

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
.PHONY: all clean fclean re bonus
.SILENT: