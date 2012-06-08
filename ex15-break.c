#include <stdio.h>
#include <string.h>

int is_command(char *command, char *input);
void print_name_and_age(char *name, int age);

int main(int argc, char *argv[])
{
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = { 
		"Alan", "Frank",
		"Mary", "John", "Lisa" 
	};
	
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	if (argc == 1 || is_command("b1", argv[1])) {
		// make cur_age point at names, using C casts.
		int *cur_age = (char *) names;
		for(i = 0; i < count; i++) {
			print_name_and_age(names[i], cur_age[i]);	
		}
	} else if (is_command("b2", argv[1])) {
		// in the final for-loop, get the math wrong in weird ways
		int *cur_age = ages;
		char **cur_name = names;
		// decrementing the pointer causes an error like this
		// "Access not within mapped region at address 0x200F0B2E3"
		for(cur_name = names, cur_age = ages;
				(cur_age - ages) < count;
				cur_name += 3, cur_age += 2)
		{
			printf("%s lived %d years so far.\n",
					*cur_name, *cur_age);
		}		
	} else if (is_command("b3", argv[1])) {
		// re-write the loops so that the go to the end of the arrays and
		// work backwards. (NOTE: Shouldn't this be extra-credit?)
		for(i = count - 1; i >= 0; i--) {
			print_name_and_age(names[i], ages[i]);
		}

		printf("---\n");
		int *cur_age = ages;
		char **cur_name = names;

		for(i = count - 1; i >=0; i--) {
			// still using the counter to offset from the start
			// of the pointer, but going backwards.
			print_name_and_age(*(cur_name + i), *(cur_age + i));
		}

		printf("---\n");
		for(i = count - 1; i >=0; i--) {
			print_name_and_age(cur_name[i], cur_age[i]);
		}

		printf("---\n");
		// Ugh. Address of operator...
		for(cur_name = &names[count - 1], cur_age = &ages[count - 1];
			(ages - cur_age) < 0;
			cur_name--, cur_age--)
		{
			print_name_and_age(*cur_name, *cur_age);
		}
	}
}

int is_command(char *command, char *input) {
	return 0 == strcmp(command, input);
}

void print_name_and_age(char *name, int age) {
	printf("%s has %d years alive.\n", name, age);
}
				
