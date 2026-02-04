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
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii += 2) {
    if (ii + 1 < i) {
        // Process two iterations at once to increase computational intensity
        float *b1 = b;
        float *b2 = b + 16;

        b1[0]  = *(ao1 + 0);   b2[0]  = *(ao1 + 2);
        b1[1]  = *(ao1 + 1);   b2[1]  = *(ao1 + 3);
        b1[2]  = *(ao2 + 0);   b2[2]  = *(ao2 + 2);
        b1[3]  = *(ao2 + 1);   b2[3]  = *(ao2 + 3);
        b1[4]  = *(ao3 + 0);   b2[4]  = *(ao3 + 2);
        b1[5]  = *(ao3 + 1);   b2[5]  = *(ao3 + 3);
        b1[6]  = *(ao4 + 0);   b2[6]  = *(ao4 + 2);
        b1[7]  = *(ao4 + 1);   b2[7]  = *(ao4 + 3);
        b1[8]  = *(ao5 + 0);   b2[8]  = *(ao5 + 2);
        b1[9]  = *(ao5 + 1);   b2[9]  = *(ao5 + 3);
        b1[10] = *(ao6 + 0);   b2[10] = *(ao6 + 2);
        b1[11] = *(ao6 + 1);   b2[11] = *(ao6 + 3);
        b1[12] = *(ao7 + 0);   b2[12] = *(ao7 + 2);
        b1[13] = *(ao7 + 1);   b2[13] = *(ao7 + 3);
        b1[14] = *(ao8 + 0);   b2[14] = *(ao8 + 2);
        b1[15] = *(ao8 + 1);   b2[15] = *(ao8 + 3);

        ao1 += 4;
        ao2 += 4;
        ao3 += 4;
        ao4 += 4;
        ao5 += 4;
        ao6 += 4;
        ao7 += 4;
        ao8 += 4;
        b += 32;
    } else {
        // Handle leftover iteration
        b[0] = *(ao1 + 0);
        b[1] = *(ao1 + 1);
        b[2] = *(ao2 + 0);
        b[3] = *(ao2 + 1);
        b[4] = *(ao3 + 0);
        b[5] = *(ao3 + 1);
        b[6] = *(ao4 + 0);
        b[7] = *(ao4 + 1);
        b[8] = *(ao5 + 0);
        b[9] = *(ao5 + 1);
        b[10] = *(ao6 + 0);
        b[11] = *(ao6 + 1);
        b[12] = *(ao7 + 0);
        b[13] = *(ao7 + 1);
        b[14] = *(ao8 + 0);
        b[15] = *(ao8 + 1);

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
}
