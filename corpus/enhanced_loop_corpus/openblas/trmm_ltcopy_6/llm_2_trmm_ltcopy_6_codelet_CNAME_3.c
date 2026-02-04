#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    b[ii * 4 + 0] = ao1[0];
    b[ii * 4 + 1] = ao1[1];
    b[ii * 4 + 2] = ao1[2];
    b[ii * 4 + 3] = ao1[3];
}
}
