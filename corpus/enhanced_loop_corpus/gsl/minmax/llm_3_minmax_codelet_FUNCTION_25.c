#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - iterate by strides of N/2 or 1 if small
    size_t stride = N > 2 ? N / 2 : 1;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Access pattern: strided access in inner loop (e.g., array[i][j])
            // Ensures non-unit stride memory accesses
            if (j + stride >= N) {
                // Ensure at least one access per row even if stride skips
                j = N - 1;
            }
        }
    }
}
