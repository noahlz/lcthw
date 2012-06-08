CC=gcc # My cc is a symlink to gcc. See: http://stackoverflow.com/q/939989/7507
CFLAGS=-Wall -g -std=c99
NAME=ex15-break
RUNCMD=./out/$(NAME)
MACRO=
PARAM1=

all: clean compile

run:
	@echo "********* RUNNING $(NAME) *********"  
	@$(RUNCMD) $(PARAM)	
	@echo "********* ENDING  $(NAME) *********"

compile:
	@echo "compiling $(NAME)..."
	$(CC) $(CFLAGS) $(MACRO) -o $(RUNCMD) $(NAME).c 

clean:
	@echo "cleaning $(NAME)..."
	@rm -f $(RUNCMD) 

grind:
	@echo "running with Valgrind..."
	valgrind $(RUNCMD) $(PARAM) 

