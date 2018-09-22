#include	<stdio.h>

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

	while(readln(line, LINESIZE, '\n') != 0)
	{
		if (wrong_format(line) == 1){
			puts(line);
			rv = 1;
		}
	}
	return rv;
}

int wrong_format(char string[])
{
	int	i;
	int	current_state = WAIT_STATE;

	for (i=0; string[i] != '\0'; i++)
	{
		if (current_state == WAIT_STATE)
		{
			if (string[i] == 'T')
			{
				current_state = T_STATE;
			}	
		} else if (current_state == T_STATE)
		{
			if (string[i] == 'I')
			{
				current_state = I_STATE;
			}
		} else if (current_state == I_STATE)
		{
			if (string[i] == '=')
			{
				current_state = EQUAL_STATE;
			}
		} else if (current_state == EQUAL_STATE)
		{	
			if (string[i] != '0' && string[i] != '1' && string[i] != '2'){
				current_state = WAIT_STATE;
				return 1;
			} else {
				current_state = WAIT_STATE;
			}
			/*
			int	HR, MM;
			HR == atoi(string[i])*10 + atoi(string[i+1]);
			MM == atoi(string[i+3])*10 + atoi(string[i+4]);
			if (HR < 0 || HR > 25)
			{
				putchar('a');
				current_state = WAIT_STATE;
				return 1;
			} else if (string[i+2] != ':')
			{
				current_state = WAIT_STATE;
				return 1;
			} else if (MM < 0 || MM > 59)
			{
				current_state = WAIT_STATE;
				return 1;
			} else {
				current_state = WAIT_STATE;
			}
			*/
		}		
		//putchar(string[i]);
	}
	return 0;
}

int readln(char buf[], int len, char delim)
{
	int	i = 0;
	int 	rv = 0;
	int	c;

	while (i<len-1 && (c = getchar()) != EOF)
	{
		rv++;
		if (c == delim)
		{
			break;
		}
		buf[i++] = c;
	}
	buf[i] = '\0';
	return rv;
}
