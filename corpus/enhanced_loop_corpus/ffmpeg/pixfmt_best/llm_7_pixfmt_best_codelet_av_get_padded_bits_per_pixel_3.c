#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int local_steps[4];
    for (i = 0; i < 4; i++)
        local_steps[i] = steps[i];
    for (c = 0; c < 4; c++)
        bits += local_steps[c];
}
