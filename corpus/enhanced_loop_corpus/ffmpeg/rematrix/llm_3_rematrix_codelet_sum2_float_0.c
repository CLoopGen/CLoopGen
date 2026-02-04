#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float *out;
extern  float *in1;
extern  float *in2;
extern integer len;
extern int i;
extern float coeff1;
extern float coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (processing array from end to start)
    for (i = len - 1; i >= 0; i--)
        out[i] = coeff1 * in1[i] + coeff2 * in2[i];
}
