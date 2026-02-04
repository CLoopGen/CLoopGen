#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *levels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    levels[0] = -100.;
    for (int i = 1; i < 15; i++) {
        levels[i] = levels[i-1]; // Introduce loop-carried WAW dependency
    }
}
