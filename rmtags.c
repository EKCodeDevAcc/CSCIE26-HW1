#include <stdio.h>
#include <ctype.h>

int
main()
{
	int c;
	int print_state = 0;	/* 0 = NOPRINT, 1 = PRINT */

	while((c=getchar()) != EOF)
	{
		if (print_state == 0) // Do not print char during no print state
		{
			if (c == '=') // If the current char is =, change current state as print
			{	
				print_state = 1;
			}
		} else if (print_state == 1)
		{
			putchar(c);	// During print state, keep printing char
			if (c == ';' || c == '\n' || c == '\t')
			{
				print_state = 0;	// Once it hits ;, new line, or tab, chage current state to no print which will stop printing the char.
			}
		}
	}
	return 0;
}
