CC=gcc
CFLAGS=-Wall -Wextra -pedantic 
-std=c99
TARGET=task

all: $(TARGET)

$(TARGET): main.c todo.c
	$(CC) $(CFLAGS) main.c todo.c -o $(TARGET)

clean:
	rm -f $(TARGET)
