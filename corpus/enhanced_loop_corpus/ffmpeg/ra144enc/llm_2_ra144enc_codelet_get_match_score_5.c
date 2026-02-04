#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern  float *data;
extern float c;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every other element)
    // First pass: process even indices
    for (i = 0; i < 40; i += 2) {
        g += work[i] * work[i];
        c += data[i] * work[i];
    }
    // Second pass: process odd indices
    for (i = 1; i < 40; i += 2) {
        g += work[i] * work[i];
        c += data[i] * work[i];
    }
}
