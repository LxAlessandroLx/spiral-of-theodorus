.PHONY: build

SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
BUILDDIR := build
TARGET := TheodorusSpiral
SRC := src/main.c src/theodorusSpiral.c
INCLUDE := -I src

build:
	$(CC) -o $(BUILDDIR)/$(TARGET) $(INCLUDE) $(SRC) $(CFLAGS)

time:
	time $(CC) -o $(BUILDDIR)/$(TARGET) $(INCLUDE) $(SRC) $(CFLAGS)

run:
	./build/$(TARGET)
