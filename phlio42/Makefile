CC = gcc
NAME = philo
DIR_SRC = src
DIR_OBJ = temp
HEADERS = includes
FLAGS = #-Wall -Wextra -Werror

SOURCES =	philo/main.c \
			philo/time.c 

SRCS = $(addprefix $(DIR_SRC)/, $(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o))

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m # No Color
ROCKET=\xf0\x9f\x9a\x80
SPARKLES=\xf0\x9f\x8c\x9f
BROOM=\xf0\x9f\x9a\xae

all: $(DIR_OBJ) $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "$(GREEN)$(ROCKET) Compilation done $(ROCKET)$(NC)"

$(DIR_OBJ):
	@mkdir -p temp
	@mkdir -p temp/philo

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<
	@echo "$(YELLOW)$(SPARKLES) Compilation of $< done $(SPARKLES)$(NC)"

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(DIR_OBJ)
	@echo "$(GREEN)$(BROOM) Clean done $(BROOM)$(NC)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BROOM) Fclean done $(BROOM)$(NC)"

re: fclean all

.PHONY: all clean fclean re