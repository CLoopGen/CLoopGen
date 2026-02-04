#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 6; ii++) {
    b[0] = ao1[ii];
    b[1] = ao2[ii];
    b[2] = ao3[ii];
    b[3] = ao4[ii];
    b[4] = ao5[ii];
    b[5] = ao6[ii];
    b += 6;
}
}
