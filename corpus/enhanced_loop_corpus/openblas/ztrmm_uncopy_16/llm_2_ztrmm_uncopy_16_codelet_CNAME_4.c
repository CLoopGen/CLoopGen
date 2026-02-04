#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 4; ii++) {
    // Variant 1: Consecutive memory access pattern
    // Interleave data from a01-a04 into a temporary array with unit stride
    float temp[8];
    temp[0] = a01[0];
    temp[1] = a01[1];
    temp[2] = a02[0];
    temp[3] = a02[1];
    temp[4] = a03[0];
    temp[5] = a03[1];
    temp[6] = a04[0];
    temp[7] = a04[1];
    
    // Write consecutively to b using unit stride
    for (BLASLONG j = 0; j < 8; j++) {
        b[j] = temp[j];
    }

    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    b += 8;
}
}
