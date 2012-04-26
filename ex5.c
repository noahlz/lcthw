#include <stdio.h>

/* This is a comment. */
int main(int argc, char *argv[])
{
	int distance = 100;

    // this is a comment
	printf("You are %d miles away.\n", distance);

    // extra credit: read the first parameter
    // run as follows: ./out/ex5 a\ gazillion
    // replaces %s with (null) if you don't specify a parameter (overflow?)
    printf("You are %s miles away.\n", argv[1]);

	return 0;
}
