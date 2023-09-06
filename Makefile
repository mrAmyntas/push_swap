NAME = push_swap

LIBFT_NAME = libft/libft.a

BONUS_NAME = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

OBJ_DIR = obj/

SRC_DIR = src/

LIBFT_DIR = libft/

BONUS_DIR = bonus/src/

SRC =	src/push_swap.c\
		src/make_array.c\
		src/calc_len.c\
		src/rotate.c\
		src/utils.c\
		src/simple.c\
		src/operations1.c\
		src/operations2.c\
		src/sort_chunks.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADER_FILES = inc/push_swap.h

all: $(OBJ_DIR) $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -o $(NAME)

$(LIBFT_NAME): $(HEADER_FILES) $(LIBFT_DIR)*.c $(LIBFT_DIR)
		make -C libft

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_FILES)
		$(CC) -c $(FLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

bonus: $(BONUS_DIR)*.c $(BONUS_DIR)
	make -C bonus

clean:
	rm -f obj/*.o

fclean: clean
	rm -f $(LIBFT_NAME)
	rm -f $(NAME)
	rm -f libft/*.o
	rm -f bonus/obj/*.o
	rm -f bonus/checker
	rm -f checker

re: fclean all

.PHONY: all clean fclean re bonus