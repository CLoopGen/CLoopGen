#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        deltas[i] = 0;
        if (i > 0)
            deltas[i] += deltas[i-1]; // Introduces RAW and loop-carried dependency (WAW via accumulation)
    }
}
