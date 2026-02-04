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
    for (ii = 0; ii < 2; ii++) {
        for (BLASLONG jj = 0; jj < 4; jj++) {
            BLASLONG idx = jj * 2;
            b[0] = ao1[idx + 0]; b[1] = ao1[idx + 1];
            b[2] = ao2[idx + 0]; b[3] = ao2[idx + 1];
            b[4] = ao3[idx + 0]; b[5] = ao3[idx + 1];
            b[6] = ao4[idx + 0]; b[7] = ao4[idx + 1];
            b[8] = ao5[idx + 0]; b[9] = ao5[idx + 1];
            b[10] = ao6[idx + 0]; b[11] = ao6[idx + 1];
            b[12] = ao7[idx + 0]; b[13] = ao7[idx + 1];
            b[14] = ao8[idx + 0]; b[15] = ao8[idx + 1];
            b += 16;
        }
        ao1 += 8; ao2 += 8; ao3 += 8; ao4 += 8;
        ao5 += 8; ao6 += 8; ao7 += 8; ao8 += 8;
    }
}
