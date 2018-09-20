#include	<stdio.h>
#include	<ctype.h>

int
main()
{
	int c;
	int print_state = 0;	// 0=NOPRINT, 1=SLASH, 2=SINGLE, 3=MULTI, 4=STAR

	while((c=getchar()) != EOF)
	{
		if (print_state == 0)	//Current state is NO PRINT
		{
			if (c == '/')
			{
				print_state = 1;
			}
		} else if (print_state == 1)
		{	if (c == '/')
			{
				putchar('/');
				putchar('/');
				print_state = 2;
			} else if (c == '*')
			{	putchar('/');
				putchar('*');
				print_state = 3;
			} else
			{
				print_state = 0;
			}
		} else if (print_state == 2)
		{
			putchar(c);
			if (c == '\n')
			{
				print_state = 0;
			}
		} else if (print_state == 3)
		{
			putchar(c);
			if (c == '*')
			{
				print_state = 4;
			}
		} else if (print_state == 4)
		{
			putchar(c);
			if (c == '/')
			{
				putchar('\n');
				print_state = 0;
			} else
			{
				print_state = 3;
			}
		}
	}
	return 0;
}
