#include <stdio.h>

int main(int argc, char *argv[]) 
{
	if(argc != 2) {
		printf("ERROR: You need one argument.\n");
		// this is how you abort a program;
		return 1;
	}

	int i = 0;
	char letter;
	// Extra credit #2 - using ',' initialize the letter in the for loop	
	for(i = 0, letter = argv[1][i]; letter != '\0'; letter = argv[1][++i]) {
		
		switch(letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;

			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case 'y':
			case 'Y':
				if(i > 2) {
					// it's only sometimes Y
					printf("%d: 'Y'\n", i);
					// Extra credit #5 - moved the break up here so that 
					// the Y character falls through to "default" case
					// when it is the first character in the word.
					break;
				}

			default:
				printf("%d: %c is not a vowel\n", i, letter);

		}
	}

	return 0;
}
