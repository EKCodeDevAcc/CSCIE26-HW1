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
	fgets(inputstr, STRSIZE, stdin );
	printf("Number? %s", inputstr);
	if (is_all_digits(inputstr) == 0)
		printf("%s is not a number.", inputstr);
	else {
		inputval = atoi(inputstr);
		put_comma(inputval);
	}
	printf("\n");	

	return 0;
}

int
is_all_digits(char str[STRSIZE] )
{
	int	i;
	for (i=0; str[i]!='\n'; i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

void
put_comma(int inputval)
{
	if (inputval < 1000)
		printf("%d", inputval);
	else {
		put_comma(inputval/1000);
		printf(",%03d", inputval%1000);
	}
}
