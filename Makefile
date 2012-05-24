CFLAGS=-Wall -g
CC=gcc
NAME=ex10
RUNCMD=./out/$(NAME)

all: clean compile

run:
	@echo "********* RUNNING $(NAME) *********"  
	@$(RUNCMD)	
	@echo "********* ENDING  $(NAME) *********"

compile:
	@echo "compiling $(NAME)..."
	$(CC) $(CFLAGS) -o $(RUNCMD) $(NAME).c 

clean:
	@echo "cleaning $(NAME)..."
	@rm -f $(RUNCMD) 

grind:
	@echo "running with Valgrind..."
	valgrind $(RUNCMD) 

