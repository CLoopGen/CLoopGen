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
        b[7] = *(a08 + 0);
        b[6] = *(a07 + 0);
        b[5] = *(a06 + 0);
        b[4] = *(a05 + 0);
        b[3] = *(a04 + 0);
        b[2] = *(a03 + 0);
        b[1] = *(a02 + 0);
        b[0] = *(a01 + 0);

        a01 += 1;
        a02 += 1;
        a03 += 1;
        a04 += 1;
        a05 += 1;
        a06 += 1;
        a07 += 1;
        a08 += 1;
        b += 8;
    }
}
