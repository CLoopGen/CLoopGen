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
    // Variant 2: Indirect (gather/scatter) memory access using an index array
    // We create a local indirect access pattern by preloading valid 'p' indices into a temporary buffer
    // This changes the access from direct sequential to indirect based on an index remapping
    // Note: We avoid dynamic allocation by assuming worst-case stack buffer (realistic for small N or bounded Ap)
    #define MAX_NNZ 1024
    int temp_idx[MAX_NNZ];
    for (j = 0; j < N; ++j) {
        size_t count = 0;
        for (int q = Ap[j]; q < Ap[j + 1]; ++q) {
            if (count < MAX_NNZ) {
                temp_idx[count++] = q;
            }
        }
        // Now traverse the inner loop indirectly via temp_idx
        for (size_t idx = 0; idx < count; ++idx) {
            int p = temp_idx[idx];
            int k = w[Ai[p]]++;
            ATi[k] = j;
        }
    }
    #undef MAX_NNZ
}
