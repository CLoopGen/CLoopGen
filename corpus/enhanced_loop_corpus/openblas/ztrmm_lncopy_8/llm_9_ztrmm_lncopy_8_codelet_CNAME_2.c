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
for (ii = 0; ii < 2; ii++) {
    b[0] = *(ao1 + 0);
    b[1] = *(ao1 + 1);
    b[2] = *(ao1 + 2);
    b[3] = *(ao1 + 3);
    b[4] = *(ao2 + 0);
    b[5] = *(ao2 + 1);
    b[6] = *(ao2 + 2);
    b[7] = *(ao2 + 3);
    b[8] = *(ao3 + 0);
    b[9] = *(ao3 + 1);
    b[10] = *(ao3 + 2);
    b[11] = *(ao3 + 3);
    b[12] = *(ao4 + 0);
    b[13] = *(ao4 + 1);
    b[14] = *(ao4 + 2);
    b[15] = *(ao4 + 3);
    ao1 += 4;
    ao2 += 4;
    ao3 += 4;
    ao4 += 4;
    b += 16;
}
}
