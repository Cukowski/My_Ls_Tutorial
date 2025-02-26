CC = gcc
CFLAGS = -Wall -Wextra -Werror  
TARGET = my_ls

.PHONY: all clean fclean re 

all: $(TARGET)

$(TARGET): my_ls.o
	$(CC) $(CFLAGS) -o $(TARGET) my_ls.o

my_ls.o: my_ls.c
	$(CC) $(CFLAGS) -c my_ls.c

clean:
	rm -f $(TARGET) *.o

fclean: clean

re: fclean all