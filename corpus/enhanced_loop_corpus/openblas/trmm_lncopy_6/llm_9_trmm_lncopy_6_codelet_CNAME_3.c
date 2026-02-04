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
for (ii = 0; ii < i * 2; ii++) {
    float val1 = *(ao1++);
    float val2 = *(ao2++);
    float val3 = *(ao3++);
    float val4 = *(ao4++);
    b[0] = val1 + val2;
    b[1] = val3 + val4;
    b[2] = val1 * val3;
    b[3] = val2 * val4;
    b += 4;
}
}
