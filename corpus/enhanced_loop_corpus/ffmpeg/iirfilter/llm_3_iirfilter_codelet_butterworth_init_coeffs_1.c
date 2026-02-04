#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride to skip elements
    // Access only even-indexed rows in a strided manner across both columns
    for (i = 2; i <= order; i += 2) {
        p[i][0] = 0.;
        p[i][1] = 0.;
    }
}
