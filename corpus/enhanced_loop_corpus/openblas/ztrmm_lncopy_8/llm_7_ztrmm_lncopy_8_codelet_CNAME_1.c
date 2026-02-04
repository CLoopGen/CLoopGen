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
for (ii = 0; ii < i; ii++) {
    b[0] = *(ao1 + 0);
    b[1] = *(ao1 + 1);
    ao1 += 2;

    b[2] = *(ao2 + 0);
    b[3] = *(ao2 + 1);
    ao2 += 2;

    b[4] = *(ao3 + 0);
    b[5] = *(ao3 + 1);
    ao3 += 2;

    b[6] = *(ao4 + 0);
    b[7] = *(ao4 + 1);
    ao4 += 2;

    b[8] = *(ao5 + 0);
    b[9] = *(ao5 + 1);
    ao5 += 2;

    b[10] = *(ao6 + 0);
    b[11] = *(ao6 + 1);
    ao6 += 2;

    b[12] = *(ao7 + 0);
    b[13] = *(ao7 + 1);
    ao7 += 2;

    b[14] = *(ao8 + 0);
    b[15] = *(ao8 + 1);
    ao8 += 2;

    b += 16;
}
}
