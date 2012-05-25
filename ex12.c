#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1) {
		// As per Extra Credit item #4
		printf("You didn't enter any command-line arguments. You suck.\n");
	
	} else if(argc > 1 && argc < 4) {
		printf("Here are your arguments:\n");

		for(i = 1; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else if(argc > 4 && argc < 10) {
		// Extra credit #2.
		printf("That's a lot of arguments. I'll print them anyway.\n");
		while(i < argc) {
			printf("%s ", argv[i]);
			i++;
		}
		printf("\n");
	} else {
		puts("You have too many arguments. You suck.\n");
	}

	// Extra credit #2
	if(argc > 1) {
		if(*argv[1] == 'Z') {
			printf("You entered the secret character. Congratuations!\n");
		}
	}

	//////////////////////////////////////////////////////////////////////////
	printf("** EXTRA CREDIT\n");
	
	// 1) Research the "boolean operators"
	// Technically, they are &&, || and !, but since since C uses 
	// numeric values for conditional tests, technically any operator
	// that returns a numeric value can be used in this manner.  
	// I.e. &, | and ^.
	if(1 & 0) { printf("1 & 0 = \"true\"\n"); } else { printf("1 & 0 = \"false\"\n"); }
	if(1 | 0) { printf("1 | 0 = \"true\"\n"); } else { printf("1 | 0 = \"false\"\n"); }
	if(1 ^ 1) { printf("1 ^ 1 = \"true\"\n"); } else { printf("1 ^ 1 = \"false\"\n"); }
	// Let's test if these operators are "short circuit" like in Java...
	if(1 > 0 && printf("If you see this, then C does not \"short circuit\" conditionals.\n")) {
		printf("short circuit test: true\n");
	} else {
		printf("short circuit test: false\n");
	}

	// 2) Add some more test cases (see above).	
 	// 3) Go back to ex10 and ex11. Add if-statements to make loops exit early
 	// using break.
 	// 4) Fix the first test so the message accurately explains to the user
 	// that they didn't enter any arguments.	
	return 0;
}
