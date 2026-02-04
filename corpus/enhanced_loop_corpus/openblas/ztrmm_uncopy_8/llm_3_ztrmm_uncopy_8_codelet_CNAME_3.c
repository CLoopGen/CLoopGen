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
BLASLONG stride = 2;
for (ii = 0; ii < i; ii++) {
    BLASLONG idx = ii * stride;
    b[ii * 8 + 0] = *(ao1 + idx);
    b[ii * 8 + 1] = *(ao1 + idx + 1);
    b[ii * 8 + 2] = *(ao2 + idx);
    b[ii * 8 + 3] = *(ao2 + idx + 1);
    b[ii * 8 + 4] = *(ao3 + idx);
    b[ii * 8 + 5] = *(ao3 + idx + 1);
    b[ii * 8 + 6] = *(ao4 + idx);
    b[ii * 8 + 7] = *(ao4 + idx + 1);
}
}
