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
    float *srcs[4] = {a01, a02, a03, a04};
    for (BLASLONG j = 0; j < 2; j++) {
        b[j*4 + 0] = srcs[0][j];
        b[j*4 + 1] = srcs[1][j];
        b[j*4 + 2] = srcs[2][j];
        b[j*4 + 3] = srcs[3][j];
    }
    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    b += 8;
}
}
