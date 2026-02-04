#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < 2; ii++) {
    b_local[0] = ao1[ii];
    b_local[1] = ao2[ii];
    b_local[2] = ao3[ii];
    b_local[3] = ao4[ii];
    b_local += 4;
}
b = b_local;
}
