#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (x = n - 1; x >= 0; x--)
        vec[x] /= sum;
}
