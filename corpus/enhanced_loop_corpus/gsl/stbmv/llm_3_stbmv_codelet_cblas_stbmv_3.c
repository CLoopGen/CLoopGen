#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  float *A;
extern  int lda;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant: Transform to indirect memory access using index arrays to decouple computation from addressing
// Simulate gather-style access by constructing index list first (avoid dynamic allocation, use direct arithmetic)

int base_ix = ((incX) > 0 ? 0 : (N - 1) * (-incX));  // Precompute base index for X
for (i = 0; i < N; i++) {
    float temp = 0.;
    const int j_min = i + 1;
    const int j_max = ((N) < (i + K + 1) ? (N) : (i + K + 1));
    int jx = base_ix + j_min * incX;

    // Use indirect, irregular but predictable access: compute full set of A and X indices ahead
    for (j = j_min; j < j_max; j++) {
        // Indirect access through computed offsets — mimics table-based or vectorizable gather
        int A_offset = lda * j + (K - j + i);
        int X_offset = jx;
        temp += *(X + X_offset) * *(A + A_offset);  // Explicit pointer arithmetic as indirect form
        jx += incX;
    }

    // Handle diagonal update with conditional logic preserved
    if (nonunit) {
        *(X + ix) = temp + *(X + ix) * *(A + lda * i + K);
    } else {
        *(X + ix) += temp;
    }
    ix += incX;
}
}
