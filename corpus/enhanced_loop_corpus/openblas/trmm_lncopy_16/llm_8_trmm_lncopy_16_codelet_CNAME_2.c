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
    for (ii = 0; ii < 16; ii++) {
        b[0] = *(a01 + 0) + *(a02 + 0);
        b[1] = *(a03 + 0) + *(a04 + 0);
        b[2] = *(a05 + 0) + *(a06 + 0);
        b[3] = *(a07 + 0) + *(a08 + 0);
        b[4] = *(a01 + 1) - *(a02 + 1);
        b[5] = *(a03 + 1) - *(a04 + 1);
        b[6] = *(a05 + 1) - *(a06 + 1);
        b[7] = *(a07 + 1) - *(a08 + 1);
        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        b += 8;
    }
}
