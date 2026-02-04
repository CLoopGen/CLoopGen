#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
for (ii = 0; ii < i; ii++) {
    b[0] = a01[ii];
    b[1] = a02[ii];
    b[2] = a03[ii];
    b[3] = a04[ii];
    b[4] = a05[ii];
    b[5] = a06[ii];
    b[6] = a07[ii];
    b[7] = a08[ii];
    b += 8;
}
}
