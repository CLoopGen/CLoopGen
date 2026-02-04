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
    // Variant 2: Strided memory access with increased stride simulation via indexing
    // Access source arrays with implicit stride of 2, but unroll and write in non-linear order
    // to simulate strided behavior in output (still logically equivalent)

    b[0] = a01[0];
    b[2] = a01[1];  // Stride 2 in b
    b[4] = a02[0];
    b[6] = a02[1];  // Stride 2
    b[1] = a03[0];  // Interleaved offset
    b[3] = a03[1];
    b[5] = a04[0];
    b[7] = a04[1];

    // Now advance pointers normally
    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    b += 8;  // Full advance after strided write
}
}
