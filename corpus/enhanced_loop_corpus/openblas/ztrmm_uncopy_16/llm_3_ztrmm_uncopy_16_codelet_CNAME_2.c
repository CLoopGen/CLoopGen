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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    BLASLONG offset = ii * 16;
    b[offset + 0]  = a01[0];
    b[offset + 2]  = a01[1];
    b[offset + 1]  = a02[0];
    b[offset + 3]  = a02[1];
    b[offset + 4]  = a03[0];
    b[offset + 6]  = a03[1];
    b[offset + 5]  = a04[0];
    b[offset + 7]  = a04[1];
    b[offset + 8]  = a05[0];
    b[offset + 10] = a05[1];
    b[offset + 9]  = a06[0];
    b[offset + 11] = a06[1];
    b[offset + 12] = a07[0];
    b[offset + 14] = a07[1];
    b[offset + 13] = a08[0];
    b[offset + 15] = a08[1];
    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    a05 += 2;
    a06 += 2;
    a07 += 2;
    a08 += 2;
}
}
