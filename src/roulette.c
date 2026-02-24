#include "roulette.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void roulette(unsigned int *mp)
{
	printf("Welcome to the roulette wheel!\n");
	printf("Pick a colour, [r]ed, or [b]lack:\n    -> ");
	
	char choice;
	unsigned int bet;
	char result;
	// get the choice from user
	scanf("%s", &choice);
	
	printf("choice: %c", choice);
	
	// some other stuff
	if (choice == 'r')		puts("ed");
	else if (choice == 'b')	puts("lack");
	else
	{ // error handling
		fflush(stdout);
		fprintf(stderr, "\nError: You have to choose exactly 'r' or 'b', not '%c'!\n", choice);
		exit(1);
	}
	
	// ask how much they are betting
	printf("How much money are you willing to bet?: [you have $%u]\n    -> ", *mp);
	fflush(stdout);
	
	scanf("%u", &bet);
	
	if (bet > *mp)
	{
		printf("you only have $%u and you want to bet $%u?!\n", *mp, bet);
		exit(1);
	}
	
	// get the result
	srand((uint)time(0));result=((char[]){114,98})[rand()%2];
		
	printf("you bet $%u\n", bet);
	
	
	if (result == choice)
	{
		*mp += bet;
		printf("you won!!! you now have $%u\n", *mp);
	}
	else
	{
		*mp -= bet;
		printf("you lost... you now have $%u\n", *mp);
	}
	printf("the wheel landed on ");
	
	if (result == 'r') printf("red\n");
	else printf("black\n");
}
