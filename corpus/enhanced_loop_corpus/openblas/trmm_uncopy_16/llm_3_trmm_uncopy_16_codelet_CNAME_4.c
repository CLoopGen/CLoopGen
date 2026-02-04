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
    BLASLONG stride = 1;
    for (ii = 0; ii < 4; ii++) {
        b[0] = *(a01 + ii * stride);
        b[1] = *(a02 + ii * stride);
        b[2] = *(a03 + ii * stride);
        b[3] = *(a04 + ii * stride);
        a01 += stride;
        a02 += stride;
        a03 += stride;
        a04 += stride;
        b += 4;
    }
}
