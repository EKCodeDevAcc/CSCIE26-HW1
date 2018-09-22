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
			if (c == '/')	//If char is /, go to SLASH state
			{
				print_state = 1;
			}
		} else if (print_state == 1)
		{	if (c == '/')	//In SLASH state, if the next char is another /, change its state as SINGLE and print two slashes
			{
				putchar('/');
				putchar('/');
				print_state = 2;
			} else if (c == '*')	// If the next char is star, chage its state as MULTI and print one slash then one star
			{	putchar('/');
				putchar('*');
				print_state = 3;
			} else	// Other than those two comes after, go back to NOPRINT state and do not print anything 
			{
				print_state = 0;
			}
		} else if (print_state == 2)
		{
			putchar(c);
			if (c == '\n') // In SINGLE state, keep printing char until it reaches to new line then change to NO PRINT state
			{
				print_state = 0;
			}
		} else if (print_state == 3)
		{
			putchar(c);
			if (c == '*') // In MULTI state, keep printing char until it reaches to another star, then change its state as STAR state
			{
				print_state = 4;
			}
		} else if (print_state == 4)
		{
			putchar(c);
			if (c == '/') // In STAR state, if slash shows up, it means that is the end of comments so print new line then change its state as NO PRINT
			{
				putchar('\n');
				print_state = 0;
			} else // Any other then that, just go back to MULTI state and keep printing
			{
				print_state = 3;
			}
		}
	}
	return 0;
}
