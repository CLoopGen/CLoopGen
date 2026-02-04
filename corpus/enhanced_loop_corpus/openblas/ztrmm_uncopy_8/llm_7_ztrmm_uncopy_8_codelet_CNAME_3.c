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
    float *local_b = b;
    const BLASLONG offset = 8;
    for (ii = 0; ii < i; ii++) {
        *(local_b + 0) = *(ao1 + 0);
        *(local_b + 2) = *(ao2 + 0);
        *(local_b + 4) = *(ao3 + 0);
        *(local_b + 6) = *(ao4 + 0);
        *(local_b + 1) = *(ao1 + 1);
        *(local_b + 3) = *(ao2 + 1);
        *(local_b + 5) = *(ao3 + 1);
        *(local_b + 7) = *(ao4 + 1);

        ao1 += 2;
        ao2 += 2;
        ao3 += 2;
        ao4 += 2;
        local_b += offset;
    }
    b = local_b; // Update global b after loop (introduces WAW dependency on b)
}
