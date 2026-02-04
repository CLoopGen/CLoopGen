#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = 2;
for (ii = 0; ii < i; ii++) {
    b[0] = *(ao1 + ii * stride);
    b[1] = *(ao2 + ii * stride);
    b[2] = *(ao3 + ii * stride);
    b[3] = *(ao4 + ii * stride);
    b[4] = *(ao5 + ii * stride);
    b[5] = *(ao6 + ii * stride);
    b += 6;
}
}
