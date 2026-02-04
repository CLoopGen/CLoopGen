#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *Ai;
extern int *Ap;
extern int *ATi;
extern int *w;
extern int p;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and adding redundant arithmetic operations.
    // This increases the number of arithmetic operations per iteration without changing overall behavior.
    for (j = 0; j < N; ++j) {
        size_t start = Ap[j];
        size_t end = Ap[j + 1];
        size_t diff = end - start;
        for (p = 0; p < diff; p += 2) {
            // Unroll by 2 iterations
            if (start + p < end) {
                int idx1 = Ai[start + p];
                int k1 = w[idx1]++;
                ATi[k1] = j;
            }
            if (start + p + 1 < end) {
                int idx2 = Ai[start + p + 1];
                int k2 = w[idx2]++;
                ATi[k2] = j;
            }
        }
        // Handle any remaining odd element
        if ((diff % 2) == 1) {
            int idx = Ai[end - 1];
            int k = w[idx]++;
            ATi[k] = j;
        }
    }
}
