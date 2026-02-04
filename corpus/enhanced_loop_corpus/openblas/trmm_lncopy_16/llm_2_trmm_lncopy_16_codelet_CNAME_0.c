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
    b[0]  = a01[ii];
    b[1]  = a02[ii];
    b[2]  = a03[ii];
    b[3]  = a04[ii];
    b[4]  = a05[ii];
    b[5]  = a06[ii];
    b[6]  = a07[ii];
    b[7]  = a08[ii];
    b[8]  = a09[ii];
    b[9]  = a10[ii];
    b[10] = a11[ii];
    b[11] = a12[ii];
    b[12] = a13[ii];
    b[13] = a14[ii];
    b[14] = a15[ii];
    b[15] = a16[ii];
    b += 16;
}
}
