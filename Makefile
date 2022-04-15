.PHONY: build

CC := gcc
CFLAGS := -Wall
RAYLIBFLAGS := -lraylib -lm
BUILDDIR := build
TARGET := TheodorusSpiral
OBJ := src/main.o src/theodorusSpiral.o
INCLUDE := -I src

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(RAYLIBFLAGS)

%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)

run:
	./build/$(TARGET)
