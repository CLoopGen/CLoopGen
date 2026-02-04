#include <stdio.h>

typedef long BLASLONG;

extern float *b;
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
for (ii = 0; ii < 256; ii += 16) {
    b[0]  = *(a01 + (ii >> 4));
    b[1]  = *(a02 + (ii >> 4));
    b[2]  = *(a03 + (ii >> 4));
    b[3]  = *(a04 + (ii >> 4));
    b[4]  = *(a05 + (ii >> 4));
    b[5]  = *(a06 + (ii >> 4));
    b[6]  = *(a07 + (ii >> 4));
    b[7]  = *(a08 + (ii >> 4));
    b[8]  = *(a09 + (ii >> 4));
    b[9]  = *(a10 + (ii >> 4));
    b[10] = *(a11 + (ii >> 4));
    b[11] = *(a12 + (ii >> 4));
    b[12] = *(a13 + (ii >> 4));
    b[13] = *(a14 + (ii >> 4));
    b[14] = *(a15 + (ii >> 4));
    b[15] = *(a16 + (ii >> 4));
    b += 16;
}
}
