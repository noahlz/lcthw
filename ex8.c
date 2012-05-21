#include <stdio.h>

int main(int argc, char *argv[])
{
	// Removing the trailing '\0' results in the following 
	// Valgrind warning: 
	// "Conditional jump or move depends on uninitialised value(s)"
	char full_name[] = {
		'Z','e','d',
		' ','A','.', ' ',
		'S','h','a','w', '\0'
	};
	
	// Note: initializing with "Z\0ed" results in just "Z" being 
	// printed everywhere. 
	char name[] = "Zed";
	
	int areas[] = {10, 12, 13, 14, 20};
	
	// The below program prints the following:
	//
	// 	  The size of an int: 4
	// 	  The size of areas (int[]): 20
	// 	  The number of ints in areas 5
	// 	  The first areas is 10, the 2nd 12.
	// 	  The size of a char: 1
	// 	  the size of name (char[]): 4
	// 	  the number of chars: 4
	// 	  The size of full_name (char[]): 12
	// 	  The number of chars: 12
	// 	  name="Zed" and full_name="Zed A. Shaw" 


	// WARNING: On some systems you may have to change the 
	// %ld in this code to %u since it will use unsigned ints
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n",
			sizeof(areas));
	printf("The number of ints in areas %ld\n",
			sizeof(areas) / sizeof(int));
	
    // Setting areas[10] prints '0' and results in valgrind warning of
    // "Conditional jump or move depends on uninitialised value(s)"
	printf("The 1st element in areas is %d, the 2nd %d.\n",
			areas[0], areas[1]);
 
	printf("The size of a char: %ld\n", sizeof(char));
	printf("the size of name (char[]): %ld\n",
			sizeof(name));
	printf("the number of chars: %ld\n",
			sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n",
			sizeof(full_name));
	printf("The number of chars: %ld\n",
			sizeof(full_name) / sizeof(char));

	// removing the trailing \0 from the full_name array results
	// in Valgrind outputing the following warning:
	// "Conditional jump or move depends on uninitialised value(s)" 
	printf("name=\"%s\" and full_name=\"%s\"\n",
			name, full_name);

	////////////////////////////////////////////////////////////////
	// EXTRA CREDIT
	puts("EXTRA CREDIT...");

	// 1) Assign elements in the areas array, for example:
	puts("Assigning 100 to areas[0]...");
	areas[0] = 100;
	printf("areas[0] = %i\n", areas[0]);

	// 2) Try assigning elements of name to full_name
	puts("Assigning the first letter of name to the Z in full name...");
	full_name[7] = name[0];
	printf("full_name is now: %s\n", full_name); // Zed A. Zhaw

	// 3) integer sizes on various CPUs
	// See: http://www.oreillynet.com/network/2003/10/07/michael_barr.html
	// - Motorola 68000 family: 16 bit = 65,536 unsigned values
	// - Cobra (A10) processor: 48 bit = 281,474,976,710,656 unsigned values
	// NOTE: The "^" operator is logical XOR. To calculate powers, you need
	// the pow() function from <math.h>
	
	////////////////////////////////////////////////////////////////
	// End Extra Credit
	
	return 0;
}
