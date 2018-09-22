Edward Kang
HW 1

Problem 0

sites.fas.harvard.edu/~edk926

The multi-user problem this C program would have is that there is a chance that multiple user opens the program at the same time, then counter cannot be updated in real time. For example, when the visitor counter number is 7, if two users hit it at the same time, the counter number will not represent the actual number of hits.

	Sample Run
	In my webstie, please click 5. User counter link
	sites.fas.harvard.edu/~edk926/counter.cgi
	You are visitor number 11



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
./extract_comments.c

	Sample Run
	./extract_comments < rmtags.c
	/* 0 = NOPRINT, 1 = PRINT */
	// Do not print char during no print state
	// If the current char is =, change current state as print
	// During print state, keep printing char
	// Once it hits ;, new line, or tab, change current state to no print which will stop printing the char.



Problem 4
./embedded_commas.c

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



Problem 5
./public_html/train-numbers
./public_html/train-numbers.cgi
./public_html/train-numbers.html

If a user input correct station name and select an option among 3 radio buttons for days, it prints out the number of trains stop at the station.

	Sample Run
	In my website, please click 6. Train Numbers link
	sites.fas.harvard.edu/~edk926/train-numbers.html
	A number of trains stop at salem on m-f
	67



Problem 6
./badtime.c

	Sample Run
	./badtime < sched
	TR=129;dir=0;day=m-f;TI=25:01;stn=machester;Line=newburyport
	.
	.
	.
	TR=314;dir=i;day=m-f;TI=99:13;stn=winchester center;Line=lowell
	.
	.
	.
	TR=329;dir=0;day=m-f;TI=:24;stn=north leominster;Line=fitchburg
	.
	.
	.
	TR=776;dir=i;day=m-f;TI=17;48;stn=fairmount;Line=fairmount
