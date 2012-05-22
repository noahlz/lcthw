#include <stdio.h>

int main(int argc, char *argv[])
{

	int numbers[4] = {0};
	
	// note: null terminator is only added if there is room.
	// see: http://stackoverflow.com/a/4348188/7507
	char name[4] = {'a'};

	// Note: when this line is moved here (as suggesd in 
	// "How to break it"), later output is garbled.
	// Also, valgrind prints: "Syscall param write(buf) points to uninitialised byte(s)"
	// and "Address 0x4c0d00a is not stack'd, malloc'd or (recently) free'd"
	// This is likely because the variable "name" was not null terminated, so
	// the printf command spills over into memory section allocated for "numbers."
	
	// int numbers[4] = {0};
	
	// first print them out raw
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);

	printf("name: %s\n", name);

	// setup the numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// setup the name
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';

	// then print them out intialized
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);

	// print the name like a string
	printf("name: %s\n", name);

	// another way to use name
	char *another = "Zed";

	printf("another %s\n", another);

	printf("another each: %c %c %c %c\n",
			another[0], another[1],
			another[2], another[3]);
	
	///////////////////////////////////////////////////////////////////////
	// EXTRA CREDIT
	
	// 1) Assign characters to numbers and then use printf to print them a
	// character at at time.
	// ANSWER: I didn't get any compiler errors. Printed out the following:
	// 	   numbers containing characters:
	// 	   97 98 99 100
	// (tried with %c format string too)
	numbers[0] = 'a';
	numbers[1] = 'b';
	numbers[2] = 'c';
	numbers[3] = 'd';
	printf("numbers containing characters:\n %d %d %d %d\n",
			numbers[0], numbers[1], numbers[2], numbers[3]);
	
	// 2) Do the inverse of (1) for name, trying to treat it like an array of
	// int and print out one int at a time. What does Valgrind think of this?
	// ANSWER: Again, no compiler errors. Valgrind doesn't care. Prints out the following:
	//     name containing numbers:
 	//     a b c d
 	// (tried with %i format string too)
	name[0] = 97;
	name[1] = 98;
	name[2] = 99;
	name[3] = 100;
	printf("name containing numbers:\n %c %c %c %c\n", 
			name[0], name[1], name[2], name[3]);

	// 3) How many other ways can you print this out?
	
	printf("name as octal:\n %o %o %o %o\n",
			name[0], name[1], name[2], name[3]);

	// This line gets the following compiler warning:
	// "format ‘%e’ expects type ‘double’, but argument 2 has type ‘int’"
	// Valgrind has many errors including this one:
	//    "Use of uninitialised value of size 8"
	// Indicating that the double is 8 bytes wide but the char value referenced
	// is much smaller?
	printf("name as double:\n %e %e %e %e\n",
			name[0], name[1], name[2], name[3]);
	printf("size of int: %ld\n", sizeof(int)); // 4
	printf("size of char: %ld\n", sizeof(char)); // 1
	printf("size of number[] element: %ld\n", sizeof(numbers[0])); // 4
	printf("size of name[] element: %ld\n", sizeof(name[0])); // 1
	printf("size of double: %ld\n", sizeof(double)); // 8
	
	// 4) If an array of characters is 4 bytes long, and an integer is 4 bytes
	// long, then you can you treat the whole name array like it's an integer?
	
	printf("size of name: %ld\n", sizeof(name));
	
	// This isn't the answer, it prints out a different value each run,
	// meaning that casting it gets you the memory address, not the "number"
	// stored in the array.
	printf("name's memory address: %lld\n", (long long int) name);
	
	// I did various searches for "covert char array to int" but many of the
	// results had to do with "string-to-int" coverstion and the function 'atoi'
	char c[4];
	c[0] = 'Z';
	c[1] = 'e';
	c[2] = 'd';
	c[3] = '\0';
	printf("chars as hex bytes: %X %X %X %X\n", c[0], c[1], c[2], c[3]);
	// How to get these into an integer? Bitwise manipulation.
	// Inspired by (not copied from) this StackOverflow question:
	// http://stackoverflow.com/q/8173037/7507
	unsigned int num;
	num = c[0] << 24;
	num = (c[1] << 16) | num;
	num = (c[2] << 8) | num;
	num = c[3] | num;
	printf("char array as hexidecimal: %X\n", num);	
	printf("char array as integer: %d\n", num);
	
	// 5) Take a piece of paper and draw out each of these arrays as a row of
	// boxes. Then code the operations you just did on paper to see if you got
	// them right.
	
	// 6) Convert name to be in the style of another and see if the code keeps
	// working.


	///////////////////////////////////////////////////////////////////////
	// End extra credit
	
	return 0;
}
	
