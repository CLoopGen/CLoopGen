#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double P[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double factor = 1.0 / 20;
    for (i = 0; i < 10; ++i) {
        P[2*i]     = factor;
        P[2*i + 1] = factor; // Unrolled loop: two assignments per iteration, fewer trips
    }
}
