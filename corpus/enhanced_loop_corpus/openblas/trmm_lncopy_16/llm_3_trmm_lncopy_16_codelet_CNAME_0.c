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
for (ii = 0; ii < 16; ii++) {
    BLASLONG index = ii * 4; // Strided access with step of 4
    b[0]  = *(a01 + index);
    b[1]  = *(a02 + index);
    b[2]  = *(a03 + index);
    b[3]  = *(a04 + index);
    b[4]  = *(a05 + index);
    b[5]  = *(a06 + index);
    b[6]  = *(a07 + index);
    b[7]  = *(a08 + index);
    b[8]  = *(a09 + index);
    b[9]  = *(a10 + index);
    b[10] = *(a11 + index);
    b[11] = *(a12 + index);
    b[12] = *(a13 + index);
    b[13] = *(a14 + index);
    b[14] = *(a15 + index);
    b[15] = *(a16 + index);
    b += 16;
}
}
