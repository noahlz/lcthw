#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 5678.4532;
	char initial = 'L';
	char first_name[] = "Noah";
	char last_name[] = "Zucker";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n",
			first_name, initial, last_name);    

	/* **************************************************
     * EXTRA CREDIT
	 * ************************************************** */

    // This line causes a segmentation fault
	/* 
	printf("My whole name is %s %c. %s.\n",
			first_name, last_name, initial);
	*/
 
	// This line outputs the following warning:
	// Warning: ex6.c:27: warning: format ‘%d’ expects type ‘int’, 
	//          but argument 2 has type ‘double’ 
	// printf("My super power number is %d.\n", power);

    // Octal literals for the British Sterling and Japanese Yen symbols. 
	printf("Supported currencies: $ \243 \245\n");
	
	// Print a number as an octal, hexidecimal and base 64.
	int number = 3405691582;
	printf("%1$d as octal = %1$o\n", number);
	printf("%1$d as hexadecimal = %1$X\n", number);
	// TODO: Base64, eh, seems like not possible with sprintf

	// print empty string
	printf("Printing an empty string: %s\n", "");

	return 0;
}
