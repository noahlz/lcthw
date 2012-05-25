#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv
	
	int i = 0;
	while(i < argc)  {
		char *arg = argv[i];
		// Ex12 Extra Credit #3
		if(*arg == 'Z') {
			printf("Detected argument starting with 'Z'! ");
			printf("Not printing any more command line arguments...\n");
			break;
		}
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;
	i = 0; // watch for this
	while(i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	////////////////////////////////////////////////////////////////////
	// EXTRA CREDIT

	// 1) Make these loops count backward by using i-- to start at argc and
	// count down to 0.
	puts("loop backwards...");
	i = num_states - 1;
	while(i >= 0) {
		printf("state %d: %s\n", i, states[i]);
		i--;
	}

	// 2) Use a while loop to copy the values from argv into states
	// 3) Make the copy loop never attempt to put more elements into
	// states[] than it has space available (seg fault otherwise).
	puts("copy argv into states...");
	i = 0;
	while(i < argc && i < num_states) {
		states[i] = argv[i];
		i++;
	}
	
	i = 0;
	while(i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;	
	}

	// 4) Research if you've really copied these strings. The answer may
	// confuse and suprise you.
	// ANSWER: you are copying the reference, not the string.
	states[1] = "Washington";
	char * blah = states[1];
	// NOTE: this doesn't compile:
	// char blah[] = states[1];
	
	puts(blah);
	printf("Address of states[1] = %X\n", &states[1]);
	printf("Address of blah = %X\n", &blah);
	
	// Got the syntax for pointer memory location from here:
	// http://stackoverflow.com/q/4301829/7507
	// Got syntax for getting the first element in a char pointer here:
	// http://www.tek-tips.com/viewthread.cfm?qid=1435212
	printf("Address of first letter of states[1] = %X\n", &(*states[1]));
	printf("Address of first letter of blah = %X\n", &(*blah));

	// Segmentation fault
	// blah[1] = 'o';
	// puts(states[1]);

	return 0;
}
