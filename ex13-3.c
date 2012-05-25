#include <stdio.h>

/////////////////////////////////////////////////////////
// Exercise 13 - Extra Credit #3
// Convert the switch statement to an if statement 
//////////////////////////////////////////////////////////

int main(int argc, char *argv[]) 
{
	if(argc == 1) {
		printf("ERROR: please enter one or more argument.\n");
		return 1;
	}

	int i;
	for(i = 1; i < argc; i++) { 
		
		char *param = argv[i];
		
		int j;	
		for(j = 0; param[j] != '\0'; j++) {
			
			char letter = param[j];
			char orig_letter = letter;
	
			if(letter >= 'A' && letter <= 'Z') {
				// PROTIP: man ascii
				letter += 32;
			}
			
			// I like the if/else approach a little better as it is more
			// compact, but I suspect that switch could be reformatted to be
			// just as compact.
			if (letter == 'a') {
				printf("%d: '%c'\n", j, orig_letter);
			} else if (letter == 'e') {
				printf("%d: '%c'\n", j, orig_letter);
			} else if (letter == 'i') {
				printf("%d: '%c'\n", j, orig_letter);
			} else if (letter == 'o') {
				printf("%d: '%c'\n", j, orig_letter);
			} else if (letter == 'u') {
				printf("%d: '%c'\n", j, orig_letter);
			} else if (letter == 'y') {
				if(i > 2) {
					// it's only sometimes Y
					printf("%d: '%c'\n", j, orig_letter);
				}
			} else {	
				printf("%d: '%c' is not a vowel\n", j, orig_letter);
			}	
		}
		if(i + 1 != argc) { printf("\n"); } // don't print on last parameter
	}

	return 0;
}
