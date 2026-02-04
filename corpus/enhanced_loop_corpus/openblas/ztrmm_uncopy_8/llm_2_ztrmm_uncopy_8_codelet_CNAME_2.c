#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of interleaving loads from ao1, ao2, ao3, ao4 in strided fashion,
    // we reorganize to process all elements consecutively from each ao pointer per iteration.
    for (ii = 0; ii < 4; ii++) {
        float temp[8];
        temp[0] = ao1[0]; temp[1] = ao1[1];
        temp[2] = ao2[0]; temp[3] = ao2[1];
        temp[4] = ao3[0]; temp[5] = ao3[1];
        temp[6] = ao4[0]; temp[7] = ao4[1];
        b[0] = temp[0]; b[1] = temp[1];
        b[2] = temp[2]; b[3] = temp[3];
        b[4] = temp[4]; b[5] = temp[5];
        b[6] = temp[6]; b[7] = temp[7];
        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        b += 8;
    }
}
