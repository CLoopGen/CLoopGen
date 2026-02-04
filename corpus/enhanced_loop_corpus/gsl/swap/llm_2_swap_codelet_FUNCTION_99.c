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
    // Variant 1: Strided memory access pattern on ATi and Ai
    // Instead of accessing Ai[p] and ATi[k] consecutively, we modify the indexing to use a fixed stride (e.g., stride of 2)
    // To maintain correctness, we ensure indices remain within bounds by adjusting loop bounds accordingly.
    size_t stride = 2;
    for (j = 0; j < N; ++j) {
        for (p = Ap[j]; p + stride - 1 < Ap[j + 1]; p += stride) {
            int k1 = w[Ai[p]]++;
            ATi[k1] = j;
            int k2 = w[Ai[p + 1]]++;
            ATi[k2] = j;
        }
        // Handle remaining elements if Ap[j+1] - Ap[j] is not divisible by stride
        for (; p < Ap[j + 1]; ++p) {
            int k = w[Ai[p]]++;
            ATi[k] = j;
        }
    }
}
