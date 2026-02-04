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
    b[0] = *(a01 + ii * 4);
    b[1] = *(a02 + ii * 4);
    b[2] = *(a03 + ii * 4);
    b[3] = *(a04 + ii * 4);
    b[4] = *(a05 + ii * 4);
    b[5] = *(a06 + ii * 4);
    b[6] = *(a07 + ii * 4);
    b[7] = *(a08 + ii * 4);
    a01 += 4;
    a02 += 4;
    a03 += 4;
    a04 += 4;
    a05 += 4;
    a06 += 4;
    a07 += 4;
    a08 += 4;
    b += 8;
}
}
