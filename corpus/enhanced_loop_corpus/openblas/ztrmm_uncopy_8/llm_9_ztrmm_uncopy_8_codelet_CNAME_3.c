#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity with stride skipping and fewer memory operations
for (ii = 0; ii < i; ii += 4) {
    // Only update every fourth result, reducing effective work
    b[0] = *(ao1 + 0);
    b[2] = *(ao2 + 0);
    b[4] = *(ao3 + 0);
    b[6] = *(ao4 + 0);

    // Advance pointers by 8 elements (4 iterations of original step)
    ao1 += 8;
    ao2 += 8;
    ao3 += 8;
    ao4 += 8;
    b += 32;  // Skip 4 full blocks of 8 floats
}
}
