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
    for (BLASLONG jj = 0; jj < 3; jj++) {
        for (ii = 0; ii < 2; ii++) {
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
}
