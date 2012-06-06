CC=gcc # My cc is a symlink to gcc. See: http://stackoverflow.com/q/939989/7507
CFLAGS=-Wall -g -std=c99
NAME=ex14-extra
RUNCMD=./out/$(NAME)
MACRO=

all: clean compile

run:
	@echo "********* RUNNING $(NAME) *********"  
	@$(RUNCMD)	
	@echo "********* ENDING  $(NAME) *********"

compile:
	@echo "compiling $(NAME)..."
	$(CC) $(CFLAGS) $(MACRO) -o $(RUNCMD) $(NAME).c 

clean:
	@echo "cleaning $(NAME)..."
	@rm -f $(RUNCMD) 

grind:
	@echo "running with Valgrind..."
	valgrind $(RUNCMD) 

