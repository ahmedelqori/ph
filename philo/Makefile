NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread
SRC = ./philo.c\
	  ./init/init_alloc.c\
	  ./init/init_data.c\
	  ./init/init_mutex.c\
	  ./init/init_philos.c\
	  ./libft/ft_atoi.c\
	  ./libft/ft_calloc.c\
	  ./check_args/check_args.c\
	  ./time/time.c\
	  ./print/errors.c\
	  ./print/status.c\
	  ./action/actions.c\
	  ./action/lock.c\
	  ./action/philo_eat.c\
	  ./action/philo_one.c\
	  ./action/philo_sleep.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
