#include <stdio.h>
#include <ctype.h>
#include <string.h> // Extra credit #2

//////////////////////////////////////////////////////////////
// EXTRA CREDIT - Exercise 14
// 1) Inline can_print_it
// 2) Have print_arguments figure out how long each argument 
// is using the strlen function, and then pass that to
// print_letters. Then re-write print_letters so it only 
// processes this fixed length and doesn't look for '\0'
// 3) Read up on isalpha and isblank with man, then use 
// similar functions to only print out digits or other 
// categories of characters.
// 4) Read about "K&R syntax"
//////////////////////////////////////////////////////////////

// forward declaration
void print_letters(char arg[], int len);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	for(i = 0; i < argc; i++) {
		// Extra Credit #2 - use strlen instead of looking for \0
		char * word = argv[i];
		int len = strlen(word);
		print_letters(word, len);
	}
}

void print_letters(char arg[], int len)
{
	int i = 0;

	for(i = 0; i < len; i++) {
		
		char ch = arg[i];

		// Extra Credit #1 - inline some functions
		// still getting an "implicit declaration" warning here
		if(isalpha(ch) || isblank(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
