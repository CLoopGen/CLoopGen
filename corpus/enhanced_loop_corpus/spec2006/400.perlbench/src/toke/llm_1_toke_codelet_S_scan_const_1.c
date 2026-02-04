#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *d;
extern I32 i;
extern I32 min;
extern I32 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 step = 1;
    for (i = min; i <= max; i += step)
        for (I32 unroll = 0; unroll < 1; unroll++)
            *d++ = (char)i;
}
