#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *d;
extern I32 i;
extern I32 min;
extern I32 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 outer = 0; outer < 1; outer++)
        for (i = min; i <= max; i++)
            *d++ = (char)i;
}
