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
    // Reduced trip count with increased per-iteration arithmetic: unroll by factor of 3
    BLASLONG bound = i - (i % 3);
    for (ii = 0; ii < bound; ii += 3) {
        // Perform three logical iterations in one
        b[0] = ao1[0]; b[1] = ao2[0]; b[2] = ao3[0]; b[3] = ao4[0]; b[4] = ao5[0]; b[5] = ao6[0];
        b[6] = ao1[1]; b[7] = ao2[1]; b[8] = ao3[1]; b[9] = ao4[1]; b[10] = ao5[1]; b[11] = ao6[1];
        b[12] = ao1[2]; b[13] = ao2[2]; b[14] = ao3[2]; b[15] = ao4[2]; b[16] = ao5[2]; b[17] = ao6[2];

        ao1 += 3;
        ao2 += 3;
        ao3 += 3;
        ao4 += 3;
        ao5 += 3;
        ao6 += 3;
        b += 18;
    }

    // Cleanup for remaining iterations (0, 1, or 2)
    for (; ii < i; ii++) {
        b[0] = *(ao1 + 0);
        b[1] = *(ao2 + 0);
        b[2] = *(ao3 + 0);
        b[3] = *(ao4 + 0);
        b[4] = *(ao5 + 0);
        b[5] = *(ao6 + 0);
        ao1++;
        ao2++;
        ao3++;
        ao4++;
        ao5++;
        ao6++;
        b += 6;
    }
}
