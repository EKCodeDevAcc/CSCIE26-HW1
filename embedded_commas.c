#include	<stdio.h>
#include	<ctype.h>
#include	<stdlib.h>

#define STRSIZE		100

int	is_all_digits(char []);
void	put_comma(int);

int
main()
{
	int	inputval = 0;
	char	inputstr[STRSIZE];
	
	printf("Enter a number: ");
	fgets(inputstr, STRSIZE, stdin );	// Get input from user
	printf("Number? %s", inputstr);		// Show input
	if (is_all_digits(inputstr) == 0)
	{
		printf("%s is not a number.", inputstr); // if it is not a number, display this message
	} else {
		inputval = atoi(inputstr);
		if (inputval >= 0) // if input is positive number, just print it
		{
			put_comma(inputval);
		} else {	// if input is negative number, add - sign in front of it
			printf("-");
			put_comma(inputval);
		}
	}
	printf("\n");	

	return 0;
}

int
is_all_digits(char str[STRSIZE] )
{
	int	i;
	for (i=1; str[i]!='\n'; i++)	// loop starts from 1, not 0 because first char can be - 
	{
		if (!isdigit(str[i]) || (str[0] != '-' && !isdigit(str[0]))) // If first char is not - sign or any other char is not digit, return 0 which will print a message it is not a number
		{
			return 0;
		}
	}
	return 1;
}

void
put_comma(int inputval)
{
	if (inputval < 1000 && inputval > 0)
	{	// If it is positive number less than 1000, just print it out
		printf("%d", inputval);
	} else if (inputval >= 1000)
	{	// If the input is beggier than 999, call this function recursively to put comma every 3 digits
		put_comma(inputval/1000);
		printf(",%03d", inputval%1000);
	} else if (inputval > -1000 && inputval < 0)
	{	// If the input is 3 or less digit, but negative, then print out its positive version since - sign will be printed out in main function
		int posval = 0;
		posval = inputval * -1;
		printf("%d", posval);		
	} else if (inputval <= -1000)
	{	// Same, just make input as positive then call it recursively, - sign will be added in main function
		int posval = 0;
		posval = inputval * -1;
		put_comma(posval/1000);
		printf(",%03d", posval%1000);
	}
}
