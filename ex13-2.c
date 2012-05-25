#include <stdio.h>

/////////////////////////////////////////////////////////
// Exercise 13 - Extra Credit #2
// Process all the arguments with another for loop.
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
	
			switch(letter) {
				case 'a':
					printf("%d: '%c'\n", j, orig_letter);
					break;
	
				case 'e':
					printf("%d: '%c'\n", j, orig_letter);
					break;
	
				case 'i':
					printf("%d: '%c'\n", j, orig_letter);
					break;
	
				case 'o':
					printf("%d: '%c'\n", j, orig_letter);
					break;
	
				case 'u':
					printf("%d: '%c'\n", j, orig_letter);
					break;
	
				case 'y':
					if(i > 2) {
						// it's only sometimes Y
						printf("%d: '%c'\n", j, orig_letter);
					}
					break;
				
				default:
					printf("%d: '%c' is not a vowel\n", j, orig_letter);
	
			}
		}
		if(i + 1 != argc) { printf("\n"); } // don't print on last parameter
	}

	return 0;
}
