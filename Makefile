CC = gcc
CFLAGS = -Wall -g

SOURCES = bst.c avl.c splay.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = tree_program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
