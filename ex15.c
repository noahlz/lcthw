#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa" 
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s has %d years alive.\n",
				names[i], ages[i]);
	}

	printf("---\n");

	// setup the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way of using pointers
	for(i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
				*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// third way, pointers are just arrays
	for(i = 0; i < count; i++) {
		printf("%s is %d years old again.\n",
				cur_name[i], cur_age[i]);
	}

	printf("---\n");
	
	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages;
			(cur_age - ages) < count; 
			cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n",
				*cur_name, *cur_age);
	}

	// "DON'T CONTINUE UNTIL YOU'VE WRITTEN DOWN WHAT YOU THINK 
	// A POINTER DOES"
	// My answer: a pointer references the beginning of a region of memory.
	// When you use the "array-style" syntax to access the data pointed to by 
	// a pointer, you are indicating the offset from that starting point.
	// The pointer++ approach actually modifies the value of the pointer (the
	// memory address) to start at a new location. The offset of the location
	// is a modulus of the size of the memory block (not sure what that means
	// for char* though, as the memory that they point to is variable length!)

	return 0;
}


