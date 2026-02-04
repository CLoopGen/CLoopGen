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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 12; ii++) {
        b[0] = *(ao1 + 0) + *(ao1 + 1);
        b[1] = *(ao2 + 0) + *(ao2 + 1);
        b[2] = *(ao3 + 0) + *(ao3 + 1);
        b[3] = *(ao4 + 0) + *(ao4 + 1);
        b[4] = *(ao5 + 0) + *(ao5 + 1);
        b[5] = *(ao6 + 0) + *(ao6 + 1);
        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        ao5 += 2;
        ao6 += 2;
        b += 6;
    }
}
