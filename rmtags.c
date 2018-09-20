#include <stdio.h>
#include <ctype.h>

int
main()
{
	int c;
	int print_state = 0;	/* 0 = NOPRINT, 1 = PRINT */

	while((c=getchar()) != EOF)
	{
		if (print_state == 0)
		{
			if (c == '=')
			{	
				print_state = 1;
			}
		} else if (print_state == 1)
		{
			putchar(c);
			if (c == ';' || c == '\n')
			{
				print_state = 0;
			}
		}
	}
	return 0;
}
