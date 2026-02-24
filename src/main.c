#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

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
		return 1;
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
	
	if (money_fp != NULL) fclose(money_fp);
	
	// perror("");
	
	printf("You have $%u\n", *mp);
	
	if (*mp == 0)
	{
		puts("\nyikes...you dont have any money\n");
		puts("do you want an extra $10 to try and get some money back?: [yn]");
		printf("    -> ");
		fflush(stdout);
		char ans;
		scanf("%c", &ans);
		
		switch (ans)
		{
			case 'y':
				puts("ok... heres $10");
				FILE *t = fopen("/tmp/.casino/.mon", "w");
				if (t == NULL)
				{
					perror("your computer wont let me give you the money..");
					exit(2);
				}
				fprintf(t, "10");
				fclose(t);
				exit(0);
				
			case 'n':
				puts("no? ok...");
				exit(0);
				
			default:
				fprintf(stderr, "you have to say exactly 'y' or 'n'!!\n");
				exit(1);
		}
	}
	
	
	printf("Mode you chose: %s\n\n", game);
	fflush(stdout);
	
	if (eq(game, "roulette"))	roulette(mp);
	else if (eq(game, "slots"))	slots(mp);
	
	else assert(false && "Invalid mode");
	
	
	
	mkdir("/tmp/.casino", 0755);
	// perror("");
	
	FILE *t = fopen("/tmp/.casino/.mon", "w+");
	
	if (t == NULL)
	{
		fprintf(stderr, "%s: cannot open file for writing: ", argv[0]);
		perror("");
		exit(2);
	}
	
	fprintf(t, "%u", *mp);
	
	if (t == NULL)
	{
		fprintf(stderr, "%s: cannot write to file: ", argv[0]);
		perror("");
		exit(2);
	}
	fclose(t);
	
	free(mp);

	return 0;
}




bool eq(char *a, char *b)
{
	return !strcmp(a, b);
}
