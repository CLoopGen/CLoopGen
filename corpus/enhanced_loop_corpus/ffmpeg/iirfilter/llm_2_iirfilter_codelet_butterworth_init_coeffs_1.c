#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array into a 1D pattern
    double *flat_p = &p[0][0];
    int len = (order + 1) * 2;
    for (i = 2; i < len; i++) {
        flat_p[i] = 0.;
    }
}
