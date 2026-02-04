#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    // Variant 2: Strided memory access pattern
    // Interleave source reads with a fixed stride to simulate non-contiguous access
    BLASLONG stride = 16;
    b[0]  = a01[0];
    b[2]  = a01[1];
    b[4]  = a02[0];
    b[6]  = a02[1];
    b[8]  = a03[0];
    b[10] = a03[1];
    b[12] = a04[0];
    b[14] = a04[1];
    b[1]  = a05[0];
    b[3]  = a05[1];
    b[5]  = a06[0];
    b[7]  = a06[1];
    b[9]  = a07[0];
    b[11] = a07[1];
    b[13] = a08[0];
    b[15] = a08[1];
    // Update pointers normally
    a01 += 2; a02 += 2; a03 += 2; a04 += 2;
    a05 += 2; a06 += 2; a07 += 2; a08 += 2;
    b += 16;
}
}
