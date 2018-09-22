#include	<stdio.h>

/*	Edward Kang
	This code is based on empites.c from the course
*/

#define	LINESIZE	512
#define WAIT_STATE	0
#define T_STATE		1
#define	I_STATE		2
#define	EQUAL_STATE	3

int wrong_format(char []);
int readln(char [], int, char);

int main()
{
	char	line[LINESIZE];
	int 	rv = 0;

	while(readln(line, LINESIZE, '\n') != 0)	// read each line of data
	{
		if (wrong_format(line) == 1){	// If there is wrong fromat of time, print the line
			puts(line);
			rv = 1;
		}
	}
	return rv;
}

int wrong_format(char string[])
{
	int	i;
	int	current_state = WAIT_STATE;	// Default state is WAIT_STATE which does nothing

	for (i=0; string[i] != '\0'; i++)
	{
		if (current_state == WAIT_STATE)
		{
			if (string[i] == 'T')	// if the char is T, change its state as T_STATE
			{
				current_state = T_STATE;
			}	
		} else if (current_state == T_STATE)
		{
			if (string[i] == 'I')	// During T_STATE, if the next char is I, move to I_STATE
			{
				current_state = I_STATE;
			}
		} else if (current_state == I_STATE)
		{
			if (string[i] == '=')	// While it is on I_STATE, if the next char is =, it means this is TI section, mvoe to EQUAL_STATE
			{
				current_state = EQUAL_STATE;
			}
		} else if (current_state == EQUAL_STATE)
		{	
			if (string[i] != '0' && string[i] != '1' && string[i] != '2')
			{	// Check if the first digit of hour is other than 0, 1, or 2
				current_state = WAIT_STATE;
				return 1;
			} else if (string[i] == '2' && string[i+1] != '0' && string[i+1] != '1' && string[i+1] != '2' && string[i+1] != '3' && string[i+1] != '4')
			{	// Since hour is 00 to 24, this will filter numbers bigger than 24		
				current_state = WAIT_STATE;
				return 1;
			} else if (string[i+2] != ':')
			{	// since hour and mintue has to be seperated by :, check if it is :
				current_state = WAIT_STATE;
				return 1;
			} else if (string[i+3] != '0' && string[i+3] != '1' && string[i+3] != '2' && string[i+3] != '3' && string[i+3] != '4' && string[i+3] != '5')
			{	// Since mintues is 00 to 59, this will filter numbers bigger than 59
				current_state = WAIT_STATE;
				return 1;
			} else
			{	// other than these, all valid time format input
				current_state = WAIT_STATE;
			}
		}		
	}
	return 0;
}

// This is from empties.c file, changed rv to rc
int readln(char buf[], int len, char delim)
{
	int	i = 0;
	int 	rc = 0;
	int	c;

	while (i<len-1 && (c = getchar()) != EOF)
	{
		rc++;
		if (c == delim)
		{
			break;
		}
		buf[i++] = c;
	}
	buf[i] = '\0';
	return rc;
}
