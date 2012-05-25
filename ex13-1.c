#include <stdio.h>

/////////////////////////////////////////////////////////
// Exercise 13 - Extra Credit #1
// Convert the upper case characters to lower case and 
// remove upper case characters from the switch block.
/////////////////////////////////////////////////////////

int main(int argc, char *argv[]) 
{
	if(argc != 2) {
		printf("ERROR: please enter exactly one argument.\n");
		return 1;
	}

	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		char orig_letter = letter;

		if(letter >= 'A' && letter <= 'Z') {
			// PROTIP: man ascii
			letter += 32;
		}

		switch(letter) {
			case 'a':
				printf("%d: '%c'\n", i, orig_letter);
				break;

			case 'e':
				printf("%d: '%c'\n", i, orig_letter);
				break;

			case 'i':
				printf("%d: '%c'\n", i, orig_letter);
				break;

			case 'o':
				printf("%d: '%c'\n", i, orig_letter);
				break;

			case 'u':
				printf("%d: '%c'\n", i, orig_letter);
				break;

			case 'y':
				if(i > 2) {
					// it's only sometimes Y
					printf("%d: '%c'\n", i, orig_letter);
				}
				break;
			
			default:
				printf("%d: '%c' is not a vowel\n", i, orig_letter);

		}
	}

	return 0;
}
