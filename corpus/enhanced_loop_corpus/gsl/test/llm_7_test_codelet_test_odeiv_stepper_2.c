#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    scale_abs[0] = 1.;
    for (i = 1; i < 15; i++) {
        scale_abs[i] = scale_abs[i-1]; // Introduce loop-carried WAW and RAW dependency
    }
}
