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
float *b_local = b;
for (ii = 0; ii < i; ii++) {
    b_local[0] = *(ao1 + 0);
    b_local[1] = *(ao1 + 1);
    b_local[2] = *(ao2 + 0);
    b_local[3] = *(ao2 + 1);
    b_local[4] = *(ao3 + 0);
    b_local[5] = *(ao3 + 1);
    b_local[6] = *(ao4 + 0);
    b_local[7] = *(ao4 + 1);

    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    b_local += 8;
}
b = b_local;
}
