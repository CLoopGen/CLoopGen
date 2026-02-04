#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access
    // Instead of accessing shape consecutively with ++, access every 2nd element (strided access)
    // Adjust loop bound to avoid out-of-bounds access
    int stride = 2;
    int limit = (width / 2) / stride;
    for (i = 0; i < limit; i++) {
        speech[i * stride] += ppc_gain * shape[i * stride];
    }
}
