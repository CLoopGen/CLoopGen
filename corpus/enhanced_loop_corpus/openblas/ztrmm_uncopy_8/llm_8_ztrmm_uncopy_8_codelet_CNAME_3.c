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
for (ii = 0; ii < i; ii += 2) {
    if (ii + 1 < i) {
        // Process two iterations at once to increase computational intensity
        float *b1 = b;
        float *b2 = b + 8;

        b1[0] = *(ao1 + 0);   b2[0] = *(ao1 + 2);
        b1[1] = *(ao1 + 1);   b2[1] = *(ao1 + 3);
        b1[2] = *(ao2 + 0);   b2[2] = *(ao2 + 2);
        b1[3] = *(ao2 + 1);   b2[3] = *(ao2 + 3);
        b1[4] = *(ao3 + 0);   b2[4] = *(ao3 + 2);
        b1[5] = *(ao3 + 1);   b2[5] = *(ao3 + 3);
        b1[6] = *(ao4 + 0);   b2[6] = *(ao4 + 2);
        b1[7] = *(ao4 + 1);   b2[7] = *(ao4 + 3);

        ao1 += 4;
        ao2 += 4;
        ao3 += 4;
        ao4 += 4;
        b += 16;
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
        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        b += 8;
    }
}
}
