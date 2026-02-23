#include "usage.h"
#include <stdio.h>

void usage(char *arg0)
{
	printf("Usage: %s [options] mode...\n", arg0);
	printf("Options:\n");
	printf("  -h,--help\tPrint this message\n");
	printf("  -v,--version\tPrint the version of the casino.\n");
	
	printf("\nModes:\n");
	printf("  roulette\tPlay roulette.\n");
	printf("  slots   \tPlay slot machines.\n"); /*
	printf("  bj      \tPlay blackjack.\n");
	printf("  poker   \tPlay poker.\n"); */
}