#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    b[0] = ao1[ii];
    b[1] = ao2[ii];
    b[2] = ao3[ii];
    b[3] = ao4[ii];
    b += 4;
}
}
