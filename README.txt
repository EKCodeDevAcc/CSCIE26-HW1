Edward Kang
HW 1

Problem 0

sites.fas.harvard.edu/~edk926

The multi-user problem this C program would have is that there is a chance that multiple user opens the program at the same time, then counter cannot be updated in real time. For example, when the visitor counter number is 7, if two users hit it at the same time, the counter number will not represent the actual number of hits.

	Sample Run
	You can check it in my website and click 5. User counter please.



Problem 1

(a) ./rmtags.c

(b) If I do reverse the order to ./semi2tab2 < sched | ./rmtags, it only removes the first tags like following:
TR=002	dir=i	day=m-f	TI=05:20	stn=middleborough/ lakeville	Line=middleborough

(c) Add c='\t' part in rmtags.c to fix this problem. Now it works before or after semi2tab2 in a pipeline.

	Sample Run
	./semi2tab2 < sched | ./rmtags | head -2
	002	i	m-f	05:20	middleborough/ lakeville	middleborough



Problem 2
(a) ./hello6.c repeat_a_message()

(b) ./hello6.c is_all_digits()
Program still works after modified repeat_a_message() into for loop and is_all_digits() for while loop.

	Sample Run
	./hello6
	Print what string? abcd
	Repeat it how many times? ee
	This is not a number: ee
	Repeat it how many times? -5
	This is not a number: -5
	Repeat it how many times? 3
	0. abcd
	1. abcd
	2. abcd



Problem 3
	Sample Run
	./extract_comments < rmtags.c
	/* 0 = NOPRINT, 1 = PRINT */
	// Do not print char during no print state
	// If the current char is =, change current state as print
	// During print state, keep printing char
	// Once it hits ;, new line, or tab, change current state to no print which will stop printing the char.



Problem 4
	Sample Run
	./embedded_commas
	Enter a number: 12
	Number? 12
	12
	Enter a number 3456789
	Number? 3456789
	3,456,789
	Enter a number: -87
	Number? -87
	-87
	Enter a number: -9654321
	Number? -9654321
	-9,654,321
	Enter a number: dd
	Number? dd
	dd
	 is not a number.
