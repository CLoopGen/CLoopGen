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
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    float *base_b = b + ii * 16;
    const BLASLONG offset = ii * 2;
    base_b[0]  = ao1[offset];
    base_b[1]  = ao1[offset + 1];
    base_b[2]  = ao2[offset];
    base_b[3]  = ao2[offset + 1];
    base_b[4]  = ao3[offset];
    base_b[5]  = ao3[offset + 1];
    base_b[6]  = ao4[offset];
    base_b[7]  = ao4[offset + 1];
    base_b[8]  = ao5[offset];
    base_b[9]  = ao5[offset + 1];
    base_b[10] = ao6[offset];
    base_b[11] = ao6[offset + 1];
    base_b[12] = ao7[offset];
    base_b[13] = ao7[offset + 1];
    base_b[14] = ao8[offset];
    base_b[15] = ao8[offset + 1];
}
}
