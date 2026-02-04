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
for (ii = 0; ii < 4; ii++) {
    BLASLONG offset = ii * 2;
    b[0] = ao1[offset + 0];
    b[1] = ao1[offset + 1];
    b[2] = ao2[offset + 0];
    b[3] = ao2[offset + 1];
    b[4] = ao3[offset + 0];
    b[5] = ao3[offset + 1];
    b[6] = ao4[offset + 0];
    b[7] = ao4[offset + 1];
    b += 8;
}
}
