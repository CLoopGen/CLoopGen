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
    BLASLONG offset;
    for (ii = 0; ii < 16; ii++) {
        offset = ii * 16;
        b[offset + 0]  = a01[ii];
        b[offset + 1]  = a02[ii];
        b[offset + 2]  = a03[ii];
        b[offset + 3]  = a04[ii];
        b[offset + 4]  = a05[ii];
        b[offset + 5]  = a06[ii];
        b[offset + 6]  = a07[ii];
        b[offset + 7]  = a08[ii];
        b[offset + 8]  = a09[ii];
        b[offset + 9]  = a10[ii];
        b[offset + 10] = a11[ii];
        b[offset + 11] = a12[ii];
        b[offset + 12] = a13[ii];
        b[offset + 13] = a14[ii];
        b[offset + 14] = a15[ii];
        b[offset + 15] = a16[ii];
    }
}
