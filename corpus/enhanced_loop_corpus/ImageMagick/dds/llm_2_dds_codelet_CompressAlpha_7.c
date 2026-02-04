#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *alphas;
extern unsigned char *indices;
extern unsigned char codes[8];
extern size_t error;
extern size_t _usr_index;
extern size_t j;
extern size_t least;
extern size_t value;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive memory access with array indexing offset to improve spatial locality
    // We process alphas and indices in reverse order to change access pattern, still maintaining correctness
    for (i = 15; i != (ssize_t)-1; i--) {
        if (alphas[i] == -1) {
            indices[i] = 0;
            continue;
        }
        value = (size_t)alphas[i];
        least = (18446744073709551615UL);
        index = 0;
        // Access codes in normal order, but unroll partially for strided perception
        for (j = 0; j < 8; j += 2) {
            size_t dist1 = value - (size_t)codes[j];
            dist1 *= dist1;
            if (dist1 < least) {
                least = dist1;
                index = j;
            }
            if (j + 1 < 8) {
                size_t dist2 = value - (size_t)codes[j + 1];
                dist2 *= dist2;
                if (dist2 < least) {
                    least = dist2;
                    index = j + 1;
                }
            }
        }
        indices[i] = (unsigned char)index;
        error += least;
    }
}
