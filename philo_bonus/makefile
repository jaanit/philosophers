NAME    = philo_bonus
CC      = gcc  
CFLAGS  = -Wall -Wextra -Werror


HEAD    = philo_bonus.h
		
OBJS    = philo_bonus.o activity_bonus.o filo.o full_eat.o  time.o \
			end_philo.o ft_isdigit.o init_bonus.o
	
all: $(NAME) $(HEAD)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
$(OBJS): $(HEAD)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all