#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii += 2) {
        if (ii + 1 < i) {
            // Process two iterations at once to increase computational intensity
            float *b1 = b;
            float *b2 = b + 4;

            b1[0] = *(ao1 + 0);
            b1[1] = *(ao1 + 1);
            b1[2] = *(ao1 + 2);
            b1[3] = *(ao1 + 3);

            b2[0] = *(ao1 + 4);
            b2[1] = *(ao1 + 5);
            b2[2] = *(ao1 + 6);
            b2[3] = *(ao1 + 7);

            b += 8;
            ao1 += 8;
        } else {
            // Handle leftover iteration
            b[0] = *(ao1 + 0);
            b[1] = *(ao1 + 1);
            b[2] = *(ao1 + 2);
            b[3] = *(ao1 + 3);
            b += 4;
            ao1 += 4;
        }
    }
}
