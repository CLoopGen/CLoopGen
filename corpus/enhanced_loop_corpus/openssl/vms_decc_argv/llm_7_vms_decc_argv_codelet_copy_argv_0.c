#include <stdio.h>

#include <inttypes.h>

extern char **newargv;
extern char *argv[];
extern int i;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= count; i++)
        newargv[i-1] = argv[i-1];
}
