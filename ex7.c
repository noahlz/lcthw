#include <stdio.h>

int main(int argc, char *argv[])
{
	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n",
			bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs.\n",
			universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n",
			expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n",
			part_of_universe);

	// this makes no sense, just a demo of something weird
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n",
			care_percentage);

	// printf("Printing null byte with %%s: %s \n", nul_byte);
	// printf("Printing null byte with %%c: %c \n", nul_byte);

	// EXTRA CREDIT
	// 1) various sizes of universe_of_defects
	//    ANSWER: "warning: integer constant is too large for its type" 
	// 2) what do these huge numbers actually print out?
	//    ANSWER: the huge number prints as 0.  part_of_universe_prints as "inf"    
	// 3) Change long to unsigned long and find the number that's too big
	//    ANSWER: the expression  
	//    unsigned long universe_of_defects = 100000000000L * 1024L * 1024L * 1024L; 
	//    has compiler error "warning: integer overflow in expression" and causes 
	//    later expressions to overflow            
	// 4) Understand what unsigned does
	//    ANSWER: Expands the maximum value that can be stored in a variable
	//    by removing the negative range.  See below:
	
	long foo = -10000L;	
	unsigned long bar = -10000L;
	printf(">> Extra credit 4:\n");
	printf("\tfoo = %ld\n", foo);	
	printf("\tbar = %lu\n", bar); // http://stackoverflow.com/q/2844/7507	
	
	// 5) explain to yourself why you can multiply char and int.
	// char is merely the numeric code for a character that can be displayed
	// on screen or printed to hard copy. As such, it is subject to
	// arithmetic. Another way of thinking about it is that a char value is a
	// pointer to an entry in a character table, and - like pointers - is subject
	// to arithmetic.
		

	///////////////////////////////////////////////////////////////////////////
    // END EXTRA CREDIT
	
	return 0;
}
