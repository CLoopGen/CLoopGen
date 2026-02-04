#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tilt;
extern float *samples;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (i = size - 1; i > 1; i -= 2)
        samples[i] -= tilt * samples[i - 2];
}
