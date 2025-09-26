CC = "gcc"
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

run: $(TARGET)
	./$(TARGET)

plot: result.csv
	python3 plot.py result.csv

table: result.csv
	python3 table.py result.csv
