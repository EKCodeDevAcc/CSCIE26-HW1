#include	<stdio.h>

/*
 * readln(char buf[], int len, char delim)
 *
 * A function to read from stdin one line.
 *    args: buf[]   an array for the chars
 *          len     size of array
 *          delim   read until one of these
 *  action: read from stdin until len-1 chars
 *          or delim appear.  Put a '\0' in
 *          the array.  
 * returns: 0 on EOF, else len+1
 *    Note: stops at EOF
 *    Note: unlike fgets, deletes the delim
 */

int readln(char buf[], int len, char delim)
{
	int	i = 0;
	int	rv = 0;
	int	c;

	/* loop while still space && more chars */
	while( i<len-1 && (c = getchar()) != EOF ){
		rv++;
		if ( c == delim )
			break;
		buf[i++] = c;
	}
	buf[i] = '\0';
	return rv;
}
