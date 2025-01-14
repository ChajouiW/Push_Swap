CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

SRC = setup.c push_swap.c sort.c setting.c stack_utils.c instractions.c instractions2.c 

BONUS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

UTILS = is_valid.c handle_input.c moves.c ft_split.c lst_utils.c more_utils.c

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o) $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)
clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

.PHONY: all clean fclean re bonus

re: fclean all
