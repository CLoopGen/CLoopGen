#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char **units;
extern double bytes;
extern double extent;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; (extent >= bytes) && (units[i + 1] != (const char *)((void *)0)) && (i < 1); i++)
        extent /= bytes;
}
