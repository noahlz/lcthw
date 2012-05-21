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
	name[3] = 'A';

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
	
	// 2) Do the inverse of (1) for name, trying to treat it like an array of
	// int and print out one int at a time. What does Valgrind think of this?
	
	// 3) How many other ways can you print this out.
	
	// 4) If an array of characters is 4 bytes long, and an integer is 4 bytes
	// long, then you can you treat the whole tname array like it's an
	// integer?
	
	// 5) Take a piece of paper and draw out each of these arrays as a row of
	// boxes. Then code the operations you just did on paper to see if you go
	// them right.
	
	// 6) Convert name to be in the style of another and see if the code keeps
	// working.


	///////////////////////////////////////////////////////////////////////
	// End extra credit
	
	return 0;
}
	
