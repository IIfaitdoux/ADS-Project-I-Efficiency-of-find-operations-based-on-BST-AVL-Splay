CC = "/c/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe"
CFLAGS = -std=c99

SOURCES = bst.c avl.c splay.c main.c testmode.c tree.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = tree_program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
