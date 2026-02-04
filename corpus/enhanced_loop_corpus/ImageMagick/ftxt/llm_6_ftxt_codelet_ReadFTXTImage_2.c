#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern long double chVals[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        chVals[i] = 0;
        if (i > 0)
            chVals[i] += chVals[i-1]; // Introduce RAW dependency: current iteration reads previous write
    }
}
