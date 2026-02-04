#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (x = n - 1; x >= 0; x--)
        vec[x] *= scale;
}
