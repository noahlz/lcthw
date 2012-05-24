#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	// go through each string in argv
	// why am I skipping argv[0]
	// (Answer: because it contains the name of the executable)
	puts("Print out command line:");
	for(i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};
	
	// setting num_states to 5 or higher can cause a seg fault.
	int num_states = 4;
	puts("Printing our own array of strings:");
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n",i, states[i]);
	}

	////////////////////////////////////////////////////////////////////
	// EXTRA CREDIT
	
	// 1) Figure out what kind of code you can put in the parts of a for-loop
	
	// 2) Look up how to use the comma character to separate multiple
	// statements in parts of the for-loop.
	// http://stackoverflow.com/q/276512/7507
	puts("multiple initializers");
	int j = 0;
	for(i = 0, j = 100; i < num_states; i++, j += 5) {
		printf("state %d: (%d) %s\n", i, j, states[i]);
	}	
	
	// skipped because it fails with seg fault
	puts("printf in the test (commented out)"); 
	// for(i = 0; i < num_states, 0 < printf("state %d: %s\n", i, states[i]); i++);

	// Putting the printf in the increment portion reuslts in state 0 being
	// skipped and "state 4: ?" or a seg fault.
	puts("printf in the incrementer (commented out)");
	// for(i = 0; i < num_states; i++, printf("state %d: %s\n", i, states[i]));

	// 3) Read what a NULL is and try to use it in one of the elements of 
	// the states array to see what it'll print. 	
	// ANSWER: See http://c-faq.com/null/macro.html 
	// Note: http://c-faq.com/null/nullor0.html states that NULL shouldn't 
	// be used to indicate the Ascii NUL (\0) character.
	states[1] = NULL; // formatted as "(null)"
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}
	
	// 4) See if you can assign an element from the states array to the argv
	// array before printing both. 
	argv[1] = states[2];
	printf("argv[1] = %s\n", argv[1]); // prints argv[1] = Washington

	argv[100] = states[3];
	printf("argv[100] = %s\n", argv[100]); // prints argv[100] = Texas	

	// Try the inverse
	states[0] = argv[0];
	printf("states[0] = %s\n", states[0]); // prints states[0] = ./out/ex10 
	
	states[3] = argv[1000];
	printf("states[3] = %s\n", states[3]); // seg fault 

	return 0;
}
