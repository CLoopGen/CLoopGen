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
for (ii = 0; ii < 16; ii++) {
    b[0] = ao1[0] + ao2[0];
    b[1] = ao1[1] + ao2[1];
    b[2] = ao3[0] + ao4[0];
    b[3] = ao3[1] + ao4[1];
    b[4] = ao5[0] + ao6[0];
    b[5] = ao5[1] + ao6[1];
    b[6] = ao7[0] + ao8[0];
    b[7] = ao7[1] + ao8[1];
    b[8] = ao1[0] - ao2[0];
    b[9] = ao1[1] - ao2[1];
    b[10] = ao3[0] - ao4[0];
    b[11] = ao3[1] - ao4[1];
    b[12] = ao5[0] - ao6[0];
    b[13] = ao5[1] - ao6[1];
    b[14] = ao7[0] - ao8[0];
    b[15] = ao7[1] - ao8[1];
    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    ao5 += 2;
    ao6 += 2;
    ao7 += 2;
    ao8 += 2;
    b += 16;
}
}
