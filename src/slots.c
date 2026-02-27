#include "slots.h"
#include "random.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#	include <Windows.h>
#else
#	include <unistd.h>
#endif

const int SPIN_PRICE = 10;

void sleep_ms(ssize_t milliseconds)
{
#ifdef _WIN32
	Sleep(milliseconds);
#else
	usleep(milliseconds * 1000);
#endif
}

void slots(uint *mp)
{
	printf("Welcome to the slot machines.\n");
	
	// printf("The slot machines are still a work in progress!\n");
	// printf("Be sure to come back later when I finish them...\n\n");
	
	// abort();
	
	printf("1 spin costs $%d;\nHow many spins do you want to buy?\n    -> ", SPIN_PRICE);
	fflush(stdout);
	
	uint spins;
	scanf("%u", &spins);
	
	if (spins > 256 || spins <= 0)
	{
		fprintf(stderr, "you have to choose a number between 1 and 256, not %u!!\n", spins);
		exit(1);
	}
	
	printf("\nyou are doing: %u spins\n", spins);
	
	if (*mp < SPIN_PRICE * spins)
	{
		fprintf(stderr, "you dont have enough money for %u spins!! (costs $%d)\n",
			spins, SPIN_PRICE * spins);
		exit(1);
	}
	
	
	*mp -= SPIN_PRICE * spins;
	
	printf("you now have $%u\n\n", *mp);
	
	int min = 0;
	int max = 7;
	
	int a,b,c;
	
	char *tmp = malloc(sizeof(char));
	
	uint gained = 0;
	
	while (--spins != (uint)-1)
	{
		printf("spins remaining: %u\n", spins);
		
		sleep_ms(50);
		a = ris1(min,max);
		sleep_ms(50);
		b = ris2(min,max);
		sleep_ms(50);
		c = ris3(min,max);
		
		printf("\n[%d]-[%d]-[%d]\n\n", a, b, c);
		
		gained += a + b + c;
		*mp += (uint)(a + b + c);
		printf("you got +$%ds\n", a + b + c);
		printf("press enter to spin again [%u spins remaining]\n", spins);
		
		sleep_ms(100);
		read(0, tmp, 1);
	}
	
	free(tmp);
	
	
	printf("\n\nin total, you gained $%d\n", gained);
	
	
	// assert(false && "TODO");
}
