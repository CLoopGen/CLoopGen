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
    float *base_b = b + ii * 8;
    const BLASLONG offset = ii * 2;
    base_b[0] = ao1[offset];
    base_b[1] = ao1[offset + 1];
    base_b[2] = ao2[offset];
    base_b[3] = ao2[offset + 1];
    base_b[4] = ao3[offset];
    base_b[5] = ao3[offset + 1];
    base_b[6] = ao4[offset];
    base_b[7] = ao4[offset + 1];
}
}
