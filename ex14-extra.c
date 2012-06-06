#include <stdio.h>
#include <ctype.h>
#include <string.h> // Extra credit #2
#include <locale.h> // Extra credit #3

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

// forward declarations
void print_chars(char arg[], int len);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	for(i = 0; i < argc; i++) {
		// Extra Credit #2 - use strlen instead of looking for \0
		char * word = argv[i];
		int len = strlen(word);
		
		print_chars(word, len);
	}
}

void print_chars(char arg[], int len)
{
	int i = 0;

	for(i = 0; i < len; i++) {
		
		char ch = arg[i];

		// Ugly use of conditional compilation instead of refactoring or
		// command-line parsing because I wanted to learn how it works.
		// NOTE: http://stackoverflow.com/q/2335888/7507
		#if use_isdigit == 1  
		// Extra Credit #3 - use other character functions
		if(isdigit(ch)) {
		#elif use_isalnum == 1
		if(isalnum(ch)) {
		#elif use_not_isalnum == 1
		if(!isalnum(ch)) {
		#else
		// Extra Credit #1 - inline some functions
		if(isalpha(ch) || isblank(ch)) {
		#endif
			printf("'%c' == %d\n", ch, ch);
		}
	}

	printf("\n");
}


int main(int argc, char *argv[])
{
	// Extra Credit #3
	// Much of the behavior of the various character functions
	// is dependant on the Locale, so I'm testing out the 
	// setlocale() function:
	char* locale_name = setlocale(LC_NAME, "");
	printf("The locale name is %s\n", locale_name);

	print_arguments(argc, argv);
	return 0;
}
