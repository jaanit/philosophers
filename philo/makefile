NAME    = philo
CC      = gcc  
CFLAGS  = -Wall -Wextra -Werror


HEAD    = philo.h
		
OBJS    = philo.o activity.o full_eat.o  time.o routine.o \
			ft_isdigit.o init.o free.o
	
all: $(NAME) $(HEAD)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
$(OBJS): $(HEAD)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all