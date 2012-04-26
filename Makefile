CFLAGS=-Wall -g
CC=gcc
NAME=ex3

all: clean compile run

run:
	@echo "********* RUNNING $(NAME) *********"  
	@./out/$(NAME)

compile:
	@echo "compiling $(NAME)..."
	@$(CC) -g -o ./out/$(NAME) $(NAME).c

clean:
	@echo "cleaning $(NAME)..."
	@rm -f ./out/$(NAME) 
