#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 8 (accessing every 8th element)
    // This creates a strided access pattern, writing in column-major like fashion
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = j * 8 + i; // Transposed indexing: stride of 8
            idct_permutation[idx] = ((idx & 7) << 3) | (idx >> 3);
        }
    }
}
