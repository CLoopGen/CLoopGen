#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *values;
extern int count;
extern double mean;
extern int cut;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (x = cut; x < count - cut; x += 2) {
        mean += values[x];
    }
}
