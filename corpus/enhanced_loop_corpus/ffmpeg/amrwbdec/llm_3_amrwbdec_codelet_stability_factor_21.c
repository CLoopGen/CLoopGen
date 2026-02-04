#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *isf;
extern  float *isf_past;
extern int i;
extern float acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates from near the end down to the start with unit stride
    for (i = 16 - 2; i >= 0; i--)
        acc += (isf[i] - isf_past[i]) * (isf[i] - isf_past[i]);
}
