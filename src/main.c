#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "usage.h"
#include "version.h"
#include "roulette.h"


bool eq(char *a, char *b);


int main(int argc, char **argv)
{
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
	
	
	// for testing purposes
	printf("game mode: %s\n", game);
	
	// if (eq(game, "slots"))
	// {
		
	// }
	
	
	return 0;
}




bool eq(char *a, char *b)
{
	return !strcmp(a, b);
}