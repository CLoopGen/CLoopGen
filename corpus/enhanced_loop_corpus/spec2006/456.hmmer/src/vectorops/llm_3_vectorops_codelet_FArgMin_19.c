#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = n - 1; i >= 1; i--)
        if (vec[i] < vec[best])
            best = i;
}
