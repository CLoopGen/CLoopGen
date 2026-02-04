#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 3; ii++) {
    b[0] = *(ao1 + 0) + *(ao1 + 6);
    b[1] = *(ao1 + 1) + *(ao1 + 7);
    b[2] = *(ao1 + 2) + *(ao1 + 8);
    b[3] = *(ao1 + 3) + *(ao1 + 9);
    b[4] = *(ao1 + 4) + *(ao1 + 10);
    b[5] = *(ao1 + 5) + *(ao1 + 11);
    b[6] = *(ao1 + 12) + *(ao1 + 18);
    b[7] = *(ao1 + 13) + *(ao1 + 19);
    b[8] = *(ao1 + 14) + *(ao1 + 20);
    b[9] = *(ao1 + 15) + *(ao1 + 21);
    b[10] = *(ao1 + 16) + *(ao1 + 22);
    b[11] = *(ao1 + 17) + *(ao1 + 23);
    ao1 += lda * 2;
    b += 12;
}
}
