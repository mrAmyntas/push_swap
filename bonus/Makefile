NAME = checker

LIBFT_NAME = ../libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

OBJ_DIR = obj/

SRC_DIR = src/

LIBFT_DIR = ../libft/

SRC =	src/checker.c\
		src/get_next_line.c\
		src/utils.c\
		src/utils2.c\
		src/operations1.c\
		src/operations2.c\
		src/operations3.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADER_FILES = inc/checker.h

all: $(OBJ_DIR) $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L../libft -lft -o $(NAME)
	cp $(NAME) ../$(NAME)

$(LIBFT_NAME): $(HEADER_FILES) $(LIBFT_DIR)*.c $(LIBFT_DIR)
		make -C ../libft

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_FILES)
		$(CC) -c $(FLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f obj/*.o
	rm -f ../libft/*.o

fclean: clean
	rm -f $(LIBFT_NAME)
	rm -f $(NAME)
	rm -f ../checker

re: fclean all

.PHONY: all clean fclean re