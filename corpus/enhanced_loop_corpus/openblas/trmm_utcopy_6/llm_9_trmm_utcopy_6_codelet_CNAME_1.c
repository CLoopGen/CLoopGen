#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count with partial unrolling and increased arithmetic per iteration
    BLASLONG limit = i / 3;
    for (ii = 0; ii < limit; ii++) {
        // Perform three logical iterations in one physical iteration
        // First segment
        b[0] = *(ao1 + 0);
        b[1] = *(ao1 + 1);
        b[2] = *(ao1 + 2);
        b[3] = *(ao1 + 3);
        b[4] = *(ao1 + 4);
        b[5] = *(ao1 + 5);

        // Second segment
        b[6] = *(ao1 + lda + 0);
        b[7] = *(ao1 + lda + 1);
        b[8] = *(ao1 + lda + 2);
        b[9] = *(ao1 + lda + 3);
        b[10] = *(ao1 + lda + 4);
        b[11] = *(ao1 + lda + 5);

        // Third segment
        b[12] = *(ao1 + 2*lda + 0);
        b[13] = *(ao1 + 2*lda + 1);
        b[14] = *(ao1 + 2*lda + 2);
        b[15] = *(ao1 + 2*lda + 3);
        b[16] = *(ao1 + 2*lda + 4);
        b[17] = *(ao1 + 2*lda + 5);

        // Update pointers once per three original iterations
        ao1 += 3 * lda;
        ao2 += 3 * lda;
        ao3 += 3 * lda;
        ao4 += 3 * lda;
        ao5 += 3 * lda;
        ao6 += 3 * lda;
        b += 18;
    }

    // Handle remaining iterations
    for (; ii < i; ii++) {
        b[0] = *(ao1 + 0);
        b[1] = *(ao1 + 1);
        b[2] = *(ao1 + 2);
        b[3] = *(ao1 + 3);
        b[4] = *(ao1 + 4);
        b[5] = *(ao1 + 5);
        ao1 += lda;
        ao2 += lda;
        ao3 += lda;
        ao4 += lda;
        ao5 += lda;
        ao6 += lda;
        b += 6;
    }
}
