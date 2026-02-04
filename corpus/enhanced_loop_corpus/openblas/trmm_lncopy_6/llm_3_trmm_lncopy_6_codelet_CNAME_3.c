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
for (ii = 0; ii < i; ii++) {
    b[(ii * 4) % 16] = *(ao1 + ii);
    b[(ii * 4 + 1) % 16] = *(ao2 + ii);
    b[(ii * 4 + 2) % 16] = *(ao3 + ii);
    b[(ii * 4 + 3) % 16] = *(ao4 + ii);
}
}
