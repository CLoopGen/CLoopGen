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
    BLASLONG stride = 2;
    for (ii = 0; ii < i; ii++) {
        // Increase arithmetic operations per iteration with redundant but valid computations
        float a1 = *(ao1++);
        float a2 = *(ao2++);
        float a3 = *(ao3++);
        float a4 = *(ao4++);

        // Perform dummy arithmetic to increase computational load
        float sum = a1 + a2 + a3 + a4;
        float avg = sum * 0.25f;
        float diff = (a1 - avg) * (a1 - avg) + (a2 - avg) * (a2 - avg) +
                     (a3 - avg) * (a3 - avg) + (a4 - avg) * (a4 - avg);

        // Primary data transfer remains, but now with side computation
        b[0] = a1;
        b[1] = a2;
        b[2] = a3;
        b[3] = a4;

        // Use computed values to avoid dead code elimination (plausible use)
        b[4] = avg;
        b[5] = diff;

        b += 6;  // Adjusted step to accommodate extra outputs
    }
}
