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
for (ii = 0; ii < i; ii++) {
    // Variant 1: Consecutive memory access pattern
    // Reorganize loads into a sequential access pattern for better spatial locality
    float *src = ao1;
    b[0] = src[0]; b[1] = src[1];
    src = ao2;
    b[2] = src[0]; b[3] = src[1];
    src = ao3;
    b[4] = src[0]; b[5] = src[1];
    src = ao4;
    b[6] = src[0]; b[7] = src[1];

    // Update all pointers consecutively
    ao1 += 2; ao2 += 2; ao3 += 2; ao4 += 2;
    b += 8;
}
}
