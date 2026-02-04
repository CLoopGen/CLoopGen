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
for (ii = 0; ii < 4; ii++) {
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a02 + 0);
    b[3] = *(a02 + 1);
    b[4] = *(a03 + 0);
    b[5] = *(a03 + 1);
    b[6] = *(a04 + 0);
    b[7] = *(a04 + 1);
    b[8] = *(a05 + 0);
    b[9] = *(a05 + 1);
    b[10] = *(a06 + 0);
    b[11] = *(a06 + 1);
    b[12] = *(a07 + 0);
    b[13] = *(a07 + 1);
    b[14] = *(a08 + 0);
    b[15] = *(a08 + 1);
    
    a01 += 4;
    a02 += 4;
    a03 += 4;
    a04 += 4;
    a05 += 4;
    a06 += 4;
    a07 += 4;
    a08 += 4;
    b += 16;
}
}
