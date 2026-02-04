#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < i; ii++) {
    b_local[0] = ao1[ii];
    b_local[1] = ao2[ii];
    b_local[2] = ao3[ii];
    b_local[3] = ao4[ii];
    b_local[4] = ao5[ii];
    b_local[5] = ao6[ii];

    b_local += 6;
}

ao1 += i;
ao2 += i;
ao3 += i;
ao4 += i;
ao5 += i;
ao6 += i;
b += 6 * i;
}
