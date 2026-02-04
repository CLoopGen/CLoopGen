#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i, j;
    unsigned int outer = 1;
    unsigned int inner = length;
    for (i = 0; i < outer; ++i)
        for (j = 0; j < inner; ++j)
            *dest++ = *source++;
}
