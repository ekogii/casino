#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "usage.h"
#include "version.h"
#include "roulette.h"
#include "slots.h"


bool eq(char *a, char *b);


int main(int argc, char **argv)
{
	errno = 0;
	
	if (argc == 1)
	{
		usage(argv[0]);
		return 0;
	}
	
	char *game = NULL;
	bool do_stuff;
	bool force_do_stuff = false;
	
	char *arg;
	
	for (int i = 1; argv[i] != NULL; i++)
	{
		arg = argv[i];
		
		// Long arguments
		if (eq(arg, "--version"))
		{
			version();
			do_stuff = false;
		}
		else if (eq(arg, "--help"))
		{
			usage(argv[0]);
			do_stuff = false;
		}
		
		// Game modes
		else if (eq(arg, "roulette"))
		{
			game = "roulette";
			force_do_stuff = true;
		}
		else if (eq(arg, "slots"))
		{
			game = "slots";
			force_do_stuff = true;
		}
		
		// Short arguments
		else if (arg[0] == '-' && strlen(arg) > 1)
		{
			if (arg[1] == '-')
			{
				fprintf(stderr, "%s: unrecognized argument '%s'\n", argv[0], arg);
				exit(1);
			}
			else
			{
				for (size_t j = 1; j < strlen(arg); j++)
				{					
					switch (arg[j])
					{
						case 'h':
							usage(argv[0]);
							do_stuff = false;
							break;
						case 'v':
							version();
							do_stuff = false;
							break;
							
						default:
							fprintf(stderr, "%s: unrecognized argument '%s'\n", argv[0], arg);
							exit(1);
					}
				}
			}
		}
		else
		{
			fprintf(stderr, "%s: unrecognized argument '%s'\n", argv[0], arg);
			exit(1);
		}
	}
	
	if (!do_stuff && game == NULL && !force_do_stuff) exit(0);
	
	unsigned int *mp = calloc(1, sizeof(unsigned int));
	assert(mp != NULL && "calloc() error");
	
	FILE *money_fp = fopen("/tmp/.casino/.mon", "r");
	
	// printf("%p, %s\n", money_fp, strerror(errno));
	
	if (money_fp == NULL) *mp = 1000;
	else if (fscanf(money_fp, "%u", mp) == 0)
		*mp = 1000;
	
	fclose(money_fp);
	
	// perror("");
	
	printf("You have $%u\n", *mp);
	
	
	printf("Mode you chose: %s\n\n", game);
	fflush(stdout);
	
	if (eq(game, "roulette"))	roulette(mp);
	else if (eq(game, "slots"))	slots(mp);
	
	else assert(false && "Invalid mode");
	
	
	if (money_fp != NULL)
	{
		FILE *t = fopen("/tmp/.casino/.mon", "w");
		fprintf(t, "%u", *mp);
		perror("");
		fclose(t);
	}
	
	free(mp);

	return 0;
}




bool eq(char *a, char *b)
{
	return !strcmp(a, b);
}
