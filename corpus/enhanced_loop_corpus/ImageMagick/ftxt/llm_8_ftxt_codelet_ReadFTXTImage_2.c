#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern long double chVals[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 2) {
        chVals[i % 64] = 0;
        chVals[(i + 1) % 64] = 0;
    }
}
