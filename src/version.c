#include "version.h"
#include "actual_version.h"

#include <stdio.h>


void version()
{
	printf("ekogii's casino -- version v%s\n", VERSION);
	fflush(stdout);
}
