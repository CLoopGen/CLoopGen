#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 on v, writing to consecutive chebmo locations
    for (i = 0; i < 13; i++) {
        chebmo[i] = v[2 * i];
    }
}
