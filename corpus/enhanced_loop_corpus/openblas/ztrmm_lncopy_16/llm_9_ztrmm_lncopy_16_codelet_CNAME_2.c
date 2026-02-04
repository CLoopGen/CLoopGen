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
    float temp1 = *(a01 + 0) + *(a02 + 0);
    float temp2 = *(a03 + 0) + *(a04 + 0);
    float temp3 = *(a05 + 0) + *(a06 + 0);
    float temp4 = *(a07 + 0) + *(a08 + 0);
    
    b[0] = temp1 * temp2;
    b[1] = temp3 * temp4;
    b[2] = temp1 + temp4;
    b[3] = temp2 + temp3;

    a01 += 1;
    a02 += 1;
    a03 += 1;
    a04 += 1;
    a05 += 1;
    a06 += 1;
    a07 += 1;
    a08 += 1;
    b += 4;
}
}
