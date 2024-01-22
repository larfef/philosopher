NAME	=	philo
SRCS	=	src/utils/atoi.c src/utils/calloc.c src/utils/free.c src/utils/print.c \
			src/utils/sleep.c src/utils/strlen.c src/utils/strncmp.c \
			src/create_thread.c src/handle_state.c src/init.c src/list.c \
			src/main.c src/parsing.c src/one_thread.c src/set_state.c
INC		=	-I inc
BIN		=	bin
CFLAGS	=	-Wall -Wextra -Werror -g
ASAN	=	-fsanitize=address
OBJS	=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
FLAGS_FILE = $(BIN)/.flags
EXISTING_FLAGS := $(shell cat $(FLAGS_FILE) 2>/dev/null)

all: check_flags $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation successful"

asan: CFLAGS += $(ASAN)
asan: check_flags all

check_flags: | $(BIN)
	@if [ "$(CFLAGS)" != "$(EXISTING_FLAGS)" ]; then \
		rm -f $(OBJS) $(NAME); \
	fi
	@echo "$(CFLAGS)" > $(FLAGS_FILE)

$(BIN)/%.o: src/%.c | $(BIN)
	@echo "$(CFLAGS)" > $(FLAGS_FILE)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/utils/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN):
	mkdir -p $(BIN)

clean:
	@if [ -e $(BIN) ]; then \
		echo "__Cleaning objects"; \
		echo "=> rm -rf $(BIN)"; \
		/bin/rm -rf $(BIN); \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		echo "__Cleaning executable"; \
		echo "=> rm -f $(NAME)"; \
		/bin/rm -f $(NAME); \
	fi

re: fclean all

.PHONY: all clean fclean re