NAME	=	philo
SRCS	=	ft_atoi.c main.c sleep.c
CFLAGS	=	-Wall -Wextra -Wextra -g
OBJS	=	$(addprefix objs/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "Compilation successful"

objs/%.o: %.c | objs
	gcc -c $< -o $@ $(CFLAGS)

objs:
	mkdir -p objs

clean:
	@if [ -e objs ]; then \
		echo -e "\n__Cleaning objects"; \
		echo -e "=> rm -rf objs\n"; \
		/bin/rm -rf objs; \
	else \
		echo -e "\n No object files to clean"; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		echo -e "\n__Cleaning executable"; \
		echo -e "=> rm -f $(NAME)"; \
		/bin/rm -f $(NAME); \
	else \
		echo -e " $(NAME) doesn't exist"; \
	fi

re: fclean all