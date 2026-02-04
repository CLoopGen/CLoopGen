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
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in the array, reducing effective iterations
    for (i = 0; i < 16 - 1; i += 2)
        acc += (isf[i] - isf_past[i]) * (isf[i] - isf_past[i]);
}
