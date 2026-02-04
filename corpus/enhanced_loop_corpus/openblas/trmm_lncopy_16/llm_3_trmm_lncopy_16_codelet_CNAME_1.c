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
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 2: Strided memory access - process every 2nd element in reverse order
BLASLONG stride = 2;
for (ii = 0; ii < i; ii++) {
    BLASLONG idx = (i - 1 - ii) * stride; // Reverse and strided index

    b[0]  = *(a01 + idx);
    b[1]  = *(a02 + idx);
    b[2]  = *(a03 + idx);
    b[3]  = *(a04 + idx);
    b[4]  = *(a05 + idx);
    b[5]  = *(a06 + idx);
    b[6]  = *(a07 + idx);
    b[7]  = *(a08 + idx);
    b[8]  = *(a09 + idx);
    b[9]  = *(a10 + idx);
    b[10] = *(a11 + idx);
    b[11] = *(a12 + idx);
    b[12] = *(a13 + idx);
    b[13] = *(a14 + idx);
    b[14] = *(a15 + idx);
    b[15] = *(a16 + idx);

    b += 16;
}
}
